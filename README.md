# Push_swap - Trier des données avec des contraintes

![C](https://img.shields.io/badge/language-C-blue.svg)
![42](https://img.shields.io/badge/school-42-000000.svg)

## 📚 À propos

**Push_swap** est un projet algorithmique de l'école 42 qui consiste à trier des données sur une pile avec un ensemble limité d'instructions et en un minimum d'opérations.

Ce projet permet de comprendre :
- Les algorithmes de tri et leur complexité
- Les structures de données (piles)
- L'optimisation algorithmique
- La manipulation de données avec des contraintes

## 🎯 Objectif

Créer un programme `push_swap` qui affiche la suite d'instructions la plus courte possible pour trier une pile d'entiers en utilisant deux piles (`a` et `b`) et un ensemble restreint d'opérations.

## 🔧 Règles

### Les deux piles
- **Pile a** : contient au départ tous les nombres (non triés)
- **Pile b** : vide au départ
- **Objectif** : trier la pile `a` en ordre croissant

### Les opérations autorisées

| Opération | Description |
|-----------|-------------|
| `sa` | **swap a** - Échange les 2 premiers éléments de la pile a |
| `sb` | **swap b** - Échange les 2 premiers éléments de la pile b |
| `ss` | `sa` et `sb` en même temps |
| `pa` | **push a** - Prend le premier élément de b et le met sur a |
| `pb` | **push b** - Prend le premier élément de a et le met sur b |
| `ra` | **rotate a** - Décale tous les éléments de a vers le haut |
| `rb` | **rotate b** - Décale tous les éléments de b vers le haut |
| `rr` | `ra` et `rb` en même temps |
| `rra` | **reverse rotate a** - Décale tous les éléments de a vers le bas |
| `rrb` | **reverse rotate b** - Décale tous les éléments de b vers le bas |
| `rrr` | `rra` et `rrb` en même temps |

## 📦 Structure du projet

```
push_swap.c           # Programme principal
push_swap.h           # Header
operations/           # Dossier des opérations (sa, sb, pa, pb, ra, rb, rra, rrb)
  ├── swap.c
  ├── push.c
  ├── rotate.c
  └── reverse_rotate.c
sorting/              # Algorithmes de tri
  ├── sort_small.c    # Tri pour 3, 4, 5 éléments
  └── sort_large.c    # Tri pour grands ensembles
utils/                # Fonctions utilitaires
  ├── parsing.c       # Parsing des arguments
  ├── stack.c         # Gestion des piles
  └── error.c         # Gestion des erreurs
Makefile              # Compilation
```

## 💻 Compilation

```bash
# Compiler le programme
make

# Nettoyer les fichiers objets
make clean

# Nettoyer tous les fichiers générés
make fclean

# Recompiler entièrement
make re
```

## 🚀 Utilisation

```bash
# Trier une liste de nombres
./push_swap 4 67 3 87 23
```

**Sortie** : Une liste d'instructions pour trier les nombres
```
pb
pb
sa
pa
pa
```

### Avec le checker (bonus)
```bash
# Vérifier si les instructions trient correctement
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Affiche "OK" si trié, "KO" sinon
```

### Compter les opérations
```bash
./push_swap 4 67 3 87 23 | wc -l
```

## 🎯 Contraintes et objectifs

### Nombre d'opérations maximum

Pour obtenir la note maximale :

| Taille | Opérations max |
|--------|----------------|
| 3 nombres | 3 opérations |
| 5 nombres | 12 opérations |
| 100 nombres | 700 opérations (5 points) |
| 100 nombres | 900 opérations (4 points) |
| 100 nombres | 1100 opérations (3 points) |
| 100 nombres | 1300 opérations (2 points) |
| 100 nombres | 1500 opérations (1 point) |
| 500 nombres | 5500 opérations (5 points) |
| 500 nombres | 7000 opérations (4 points) |
| 500 nombres | 8500 opérations (3 points) |
| 500 nombres | 10000 opérations (2 points) |
| 500 nombres | 11500 opérations (1 point) |

## 🧠 Stratégies de tri

### 1. Tri pour 3 éléments
Approche directe avec conditions (max 3 opérations)

### 2. Tri pour 4-5 éléments
- Pousser les plus petits vers `b`
- Trier `a`
- Repousser vers `a`

### 3. Tri pour grands ensembles (100-500)

**Approches populaires :**
- **Algorithme par chunks** : diviser en groupes et trier par morceaux
- **Radix sort** : tri par bits
- **Algorithme Turk** : optimisation avec coût de déplacement
- **Algorithme butterfly** : diviser en deux parties

## 📖 Gestion des erreurs

Le programme doit gérer :
- Arguments non numériques
- Nombres en dehors de `INT_MIN` / `INT_MAX`
- Doublons
- Liste vide
- Liste déjà triée (aucune opération à afficher)

En cas d'erreur, afficher `"Error\n"` sur `stderr`.

```c
// Exemples d'erreurs
./push_swap 1 2 3 a       // "Error" (non numérique)
./push_swap 1 2 2 3       // "Error" (doublon)
./push_swap 2147483648    // "Error" (dépassement)
```

## 🧪 Tests

### Tests basiques
```bash
# Liste déjà triée (aucune sortie)
./push_swap 1 2 3 4 5

# 3 nombres
./push_swap 2 1 3

# 5 nombres
./push_swap 5 4 3 2 1
```

### Tests avec nombres aléatoires
```bash
# Générer 100 nombres aléatoires
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l
```

### Vérifier avec le checker
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Doit afficher "OK"
```

### Testeurs recommandés
- [push_swap_tester](https://github.com/gemartin99/Push-Swap-Tester)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

## 💡 Conseils

1. **Commencez simple** : implémentez d'abord le tri pour 3 éléments
2. **Testez chaque opération** : assurez-vous qu'elles fonctionnent correctement
3. **Optimisez progressivement** : commencez par un algorithme basique puis optimisez
4. **Visualisez** : utilisez un visualizer pour comprendre vos mouvements
5. **Gérez les erreurs** : testez tous les cas limites

## 👨‍💻 Auteur

Projet réalisé dans le cadre du cursus de l'école 42.

## 📝 Note

Push_swap est un excellent projet pour développer sa logique algorithmique et comprendre les compromis entre différentes approches de tri. C'est également une bonne préparation aux entretiens techniques !

---

*"Sometimes the most efficient solution requires thinking outside the stack."* 📚✨
