
# Generic-typing.git - Generic Typing in C

Une petite bibliothèque en **C** qui permet de stocker et manipuler des valeurs de types primitifs de manière générique via un système de **type tagging**.

Le projet repose sur une structure `Value` qui encapsule :

- un pointeur vers la donnée,
- son type,
- sa taille en mémoire.

L’objectif est de fournir une base simple pour gérer des données dynamiques de façon abstraite, tout en gardant un comportement clair et explicite. En plus de pouvoirs executer
en un clic si vous utilisez bash grace a un mini script associe.

---

## Fonctionnalités

- Création dynamique d’une valeur générique
- Libération sécurisée de la mémoire
- Affichage selon le type réel de la donnée
- Remplacement d’une valeur par une autre
- Support des types suivants :
  - `BOOL`
  - `CHAR`
  - `INT`
  - `FLOAT`
  - `DOUBLE`

---

## Structure du projet

```bash
.
├── include/
│   └── generic_typing.h
├── src/
│   ├── generic_typing.c
│   └── main.c
├── exec.sh
└── README.md
```
