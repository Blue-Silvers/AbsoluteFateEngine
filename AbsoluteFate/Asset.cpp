#include "Asset.h"

#include "tiny_obj_loader.h"
#include "Log.h"
#include <sstream>
#include <filesystem>

map<string, Texture> Asset::mTexturesMap = {};
map<string, vector<Texture> > Asset::mAnimationMap = {};
map<string, Mesh> Asset::mMeshMap = {};

Texture Asset::LoadTextureFromFile(IRenderer& pRenderer, const string& pFileName)
{
	Texture texture;
	texture.LoadTexture(&pRenderer, pFileName);
	return texture;
}

Mesh Asset::LoadMeshFromFile(const string& pFileName)
{
	Mesh loaded;
	tinyobj::attrib_t attributes;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warning, errors;
	//std::string dir = "Meshes/";
	bool success = tinyobj::LoadObj(&attributes, &shapes, &materials, &warning, &errors, +pFileName.c_str());
	if (!success)
	{
		Log::Error(LogType::Application, "Mesh " + pFileName + " does not exist or is not .obj");
		return Mesh();
	}
	else
	{
		Log::Info("Mesh " + pFileName + " successfully loaded");
	}
	std::vector<Vertex> vertices;

	for (int i = 0; i < shapes.size(); i++)
	{
		tinyobj::shape_t& shape = shapes[i];
		tinyobj::mesh_t& mesh = shape.mesh;
		for (int j = 0; j < mesh.indices.size(); j++)
		{
			tinyobj::index_t i = mesh.indices[j];
			Vector3 position = Vector3{
				attributes.vertices[i.vertex_index * 3],
				attributes.vertices[i.vertex_index * 3 + 1],
				attributes.vertices[i.vertex_index * 3 + 2]
			};
			Vector3 normal = Vector3{
				attributes.normals[i.normal_index * 3],
				attributes.normals[i.normal_index * 3 + 1],
				attributes.normals[i.normal_index * 3 + 2]
			};
			Vector2 texCoord = {
				attributes.texcoords[i.texcoord_index * 2],
				attributes.texcoords[i.texcoord_index * 2 + 1],
			};
			// Not gonna care about texCoord right now.
			Vertex vert = { position, normal, texCoord };
			vertices.push_back(vert);
		}

	}
	return Mesh(vertices);
}

Mesh Asset::LoadMesh(const string& pFileName, const string& pMeshName)
{
	mMeshMap[pMeshName] = LoadMeshFromFile(pFileName);
	return mMeshMap[pMeshName];
}

Mesh& Asset::GetMesh(const string& pMeshName)
{
	if (mMeshMap.find(pMeshName) == mMeshMap.end())
	{
		ostringstream loadError;
		loadError << "Texture " << pMeshName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return mMeshMap[pMeshName];
}

Texture Asset::LoadTexture(IRenderer& pRenderer, const string& pFileName, const string& pTextureName)
{
	mTexturesMap[pTextureName] = LoadTextureFromFile(pRenderer, pFileName);
	return mTexturesMap[pTextureName];
}

vector<Texture> Asset::LoadAllTextureFromFolder(IRenderer& pRenderer, const string& pFileName, const string& pAnimationName)
{
	filesystem::directory_iterator it(pFileName);

	for (const auto& entry : it) 
	{
		auto& filePath = entry.path();
		if (entry.is_directory()) 
		{
			continue;
		}
		Texture texture = LoadTexture(pRenderer, filePath.string(), filePath.filename().replace_extension().string());
		mAnimationMap[pAnimationName].push_back(texture);
	}

	return mAnimationMap[pAnimationName];
}

Texture& Asset::GetTexture(const string& pTextureName)
{
	if (mTexturesMap.find(pTextureName) == mTexturesMap.end()) 
	{
		ostringstream loadError;
		loadError << "Texture " << pTextureName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return mTexturesMap[pTextureName];
}

vector<Texture>& Asset::GetAnimation(const string& pAnimationName)
{
	if (mAnimationMap.find(pAnimationName) == mAnimationMap.end())
	{
		ostringstream loadError;
		loadError << "Animation " << pAnimationName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return  mAnimationMap[pAnimationName];
}

void Asset::ClearMap()
{
	for (auto iter : mTexturesMap)
	{
		iter.second.UnloadTexture();
	}
	mTexturesMap.clear();
}