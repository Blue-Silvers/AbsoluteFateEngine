#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "Vector3.h"
#include "Maths.h"

class Transform3D
{
private:
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;

	bool mWorldTransformNeedsRecomputed;

public:
	Transform3D() :position(0, 0, 0), scale(1, 1, 1), rotation(0, 0, 0), mWorldTransformNeedsRecomputed(true){};
	Transform3D(Vector3 pPosition = Vector3::zero, Vector3 pScale = Vector3::one, Vector3 pRotation = Vector3::zero) : position(pPosition),
																										scale(pScale), 
																										rotation(pRotation), 
																										mWorldTransformNeedsRecomputed(true) {};
	
	Transform3D(Transform pTranstorm2D, float pZpos = 0, float pZscale = 0, Vector2 pZrot = 0) : position(pTranstorm2D.GetPosition().x, pTranstorm2D.GetPosition().y, pZpos),
																									scale(pTranstorm2D.GetScale().x, pTranstorm2D.GetScale().y, pZscale),
																									rotation(pZrot.x, pZrot.y, pTranstorm2D.GetRotation()),
																									mWorldTransformNeedsRecomputed(true) {};

	void ComputeWorldTransform();

	//Directions
	Vector3 Right() const { return Vector3(Maths::Cos(rotation.z), -Maths::Sin(rotation.z), 0); }
	Vector3 Up() const { return Vector3(Maths::Sin(rotation.z), -Maths::Cos(rotation.z), 0); }

	//Getter
	Vector3 GetScale() const { return scale; };
	Vector3 GetPosition() const { return position; };
	Vector3 GetRotation() const { return rotation; };
};

