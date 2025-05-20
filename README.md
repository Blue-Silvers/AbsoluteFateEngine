# AbsoluteFateEngine - DOOM
AbsoluteFateEngine est un moteur de jeu 3D développé en C++ avec OpenGL, inspiré du gameplay classique de DOOM. Cette branche DOOM est dédiée à la création d'un prototype de jeu de tir à la première personne (FPS) en 3D.

## 📌 Vidéo démo :


https://github.com/user-attachments/assets/c724594a-6b7e-4412-8e51-a658fac8b5d6



## 🎮 Fonctionnalités principales
- Rendu 3D en temps réel avec OpenGL (mode immédiat)

- Système de raycasting 3D avec détection de collision contre des boîtes axis-aligned (AABB)

- Contrôles de base du joueur (déplacement, orientation)

- Affichage de HUD minimaliste

- Structure de code modulaire pour faciliter l'ajout de nouvelles fonctionnalités

## 🧰 Dépendances
- GLFW pour la gestion de la fenêtre et des entrées clavier/souris

- OpenGL pour le rendu graphique

- GLM pour les mathématiques 3D (facultatif, selon les besoins)

## 🕹️ Input

| Touche(s)     | Action                        |
|---------------|-------------------------------|
| `Z`           | Avancer                       |
| `S`           | Reculer                       |
| `Q` / `D`     | Déplacement latéral gauche/droite |
| Souris        | Orientation de la caméra      |
| `Entrée`      | Prendre le contrôle du joueur |
| `Échap`       | Quitter le jeu                |

## 🛠️ Structure du projet
- AbsoluteFate/ : Contient les fichiers sources principaux du moteur

- Dependencies/ : Bibliothèques tierces nécessaires au projet

- AbsoluteFate.sln : Fichier de solution pour Visual Studio
