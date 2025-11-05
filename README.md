# Push_Swap - Tri optimisé avec deux piles

![C](https://img.shields.io/badge/language-C-blue.svg)
![42](https://img.shields.io/badge/school-42-000000.svg)

## 📚 À propos

**Push_Swap** est un algorithme de tri utilisant deux piles et un ensemble limité d'opérations. L'objectif est de trier les nombres en un minimum de mouvements.

Implémentation personnelle par **aherman** (@arnaudherman) - 42 Lausanne

## 🎯 Objectif

Trier une pile d'entiers en ordre croissant avec le moins d'opérations possible en utilisant deux piles (`a` et `b`) et des opérations restreintes.

## 🏗️ Architecture du code

### Organisation des fichiers

```
src/
├── push_swap.c              # Programme principal
├── check_args.c             # Validation des arguments
├── check_atoi.c             # Conversion et validation nombres
├── check_split.c            # Split personnalisé
├── sort_main.c              # Dispatch selon la taille
├── sort_three.c             # Tri optimal pour 3 éléments
├── sort_five.c              # Tri pour 4-5 éléments
├── sort_for.c               # Tri pour 4 éléments
├── sort_big.c               # Algorithme principal grands ensembles
├── sort_big_opti.c          # Optimisations (calcul coûts)
├── sort_big_utils.c         # Utilitaires tri grands ensembles
├── sort_utils.c             # Utilitaires généraux
├── instruction_*.c          # Implémentation opérations (sa, pb, ra, etc.)
├── free_utils.c             # Gestion mémoire
include/
└── pushswap.h              # Structures + prototypes
ft_printf/                   # ft_printf intégré
```

## 🧠 Votre algorithme de tri

### 1. Tri pour 2 éléments
```c
if (size == 2)
    instruction(1, stack_a, stack_b, "sa");
```
Simple swap si nécessaire.

### 2. Tri pour 3 éléments - Optimal par permutation

```c
void sort_three(t_list *stack_a, t_list *stack_b)
{
    int comb = get_permutation(stack_a);
    
    if (comb == 132) instructionf(2, stack_a, stack_b, "rra", "sa");
    if (comb == 213) sa_sb(stack_a, stack_b, "sa");
    if (comb == 231) rra_rrb(stack_a, stack_b, "rra");
    if (comb == 312) ra_rb(stack_a, stack_b, "ra");
    if (comb == 321) instructionf(2, stack_a, stack_b, "sa", "rra");
}
```

**Particularité :** Identifie la permutation exacte et applique la séquence optimale (max 2 opérations).

### 3. Tri pour 5 éléments

```c
void sort_five(t_list *stack_a, t_list *stack_b)
{
    // Trouve le 2ème plus petit élément
    int i = second_smallest(stack_a);
    i = get_index(stack_a, i);
    
    // Le positionne et le pousse vers b selon sa position
    if (i == 0) instructionf(1, stack_a, stack_b, "pb");
    if (i == 1) instructionf(2, stack_a, stack_b, "sa", "pb");
    if (i == 2) instructionf(3, stack_a, stack_b, "ra", "ra", "pb");
    if (i == 3) instructionf(3, stack_a, stack_b, "rra", "rra", "pb");
    if (i == 4) instructionf(2, stack_a, stack_b, "rra", "pb");
}
```

**Stratégie :** Pousse le 2ème plus petit vers `b`, trie le reste, puis réinsère.

### 4. Algorithme pour grands ensembles (> 5)

Votre implémentation utilise un **algorithme de coût minimum** :

#### Phase 1 : Réduction à 3 éléments

```c
void big_sort(t_list *stack_a, t_list *stack_b)
{
    // Pousse 2 éléments vers b
    instruction(2, stack_a, stack_b, "pb", "pb");
    
    // Tant qu'il reste plus de 3 éléments dans a
    while (stack_size(stack_a) > 3)
    {
        c = cheapest_op(stack_a, stack_b);  // Trouve l'élément le moins coûteux
        
        // Calcule les rotations communes (rr/rrr)
        c.ops_ab = rrr_ops(c.ops_a, c.ops_b);
        
        // Effectue les rotations
        rotrev_ops(stack_a, stack_b, c.ops_ab, "r");      // Rotations communes
        rotrev_ops(stack_a, stack_b, c.ops_a - c.ops_ab, "a");  // Reste a
        rotrev_ops(stack_a, stack_b, c.ops_b - c.ops_ab, "b");  // Reste b
        
        pa_pb(stack_a, stack_b, "pb");
    }
    
    // Trie les 3 derniers éléments de a
    sort_three(stack_a, stack_b);
    
    // Réinsère tous les éléments de b vers a
    pa_sorting(stack_a, stack_b);
}
```

#### Algorithme `cheapest_op()` - Coeur de l'optimisation

```c
t_best_ops cheapest_op(t_list *stack_a, t_list *stack_b)
{
    // Définit les limites (chunks)
    limit[0] = 4;
    limit[1] = stack_size(stack_a) - 4;
    
    // Pour > 100 éléments, élargit les chunks
    if (stack_size(stack_a) + stack_size(stack_b) > 100)
    {
        limit[0] = 8;
        limit[1] = stack_size(stack_a) - 8;
    }
    
    // Trouve l'élément avec le coût minimal
    cheap.best_pos = min_ops(stack_a, stack_b, limit[0], limit[1]);
    cheap.close_pos = get_closest(cheap.best_pos, stack_b);
    cheap.ops_a = count_op(stack_a, cheap.best_pos->position);
    cheap.ops_b = count_op(stack_b, cheap.close_pos);
}
```

**Votre stratégie :**
1. **Chunking** : Divise la pile en chunks (4 ou 8 selon la taille)
2. **Recherche de cible** : Pour chaque élément, trouve sa position cible dans `b` avec `get_closest()`
3. **Calcul du coût** : Compte les opérations nécessaires (`ra`/`rra` + `rb`/`rrb`)
4. **Optimisation `rr`/`rrr`** : Combine les rotations communes
5. **Coût total** : Calcule `total_ops(ops_a, ops_b)` qui gère les rotations combinées

#### Fonction `get_closest()` - Placement intelligent

```c
int get_closest(t_element *element, t_list *stack_b)
```

**Ce qu'elle fait :**
- Parcourt toute la pile `b`
- Trouve l'élément le plus proche en valeur
- Retourne la position optimale pour insérer

#### Phase 2 : Réinsertion depuis b vers a

```c
void pa_sorting(t_list *stack_a, t_list *stack_b)
{
    while (stack_size(stack_b) > 0)
    {
        c.close_pos = get_closest(stack_b->first, stack_a);
        c.ops_a = count_op(stack_a, c.close_pos);
        rotrev_ops(stack_a, stack_b, c.ops_a, "a");
        
        if (stack_b->first->position < c.close_pos)
            pa_pb(stack_a, stack_b, "pa");
        else
            instruction(2, stack_a, stack_b, "ra", "pa");
    }
    
    // Rotation finale pour mettre le plus petit en haut
    c.ops_a = count_op(stack_a, 1);
    rotrev_ops(stack_a, stack_b, c.ops_a, "a");
}
```

## 🔧 Structures de données

### Structure de la pile

```c
typedef struct s_element
{
    int              nbr;         // Valeur
    int              position;    // Position relative (rang)
    int              index;       // Index dans la pile
    struct s_element *nxt;        // Élément suivant
}   t_element;

typedef struct s_list
{
    t_element   *first;
    t_element   *last;
}   t_list;
```

### Structure d'optimisation

```c
typedef struct s_best_ops
{
    t_element   *best_pos;    // Meilleur élément à pousser
    int         close_pos;    // Position cible dans l'autre pile
    int         ops_a;        // Opérations nécessaires pile a
    int         ops_b;        // Opérations nécessaires pile b
    int         ops_ab;       // Opérations communes (rr/rrr)
}   t_best_ops;
```

## 💻 Compilation

```bash
make        # Compile le projet
make clean  # Nettoie les .o
make fclean # Nettoie tout
make re     # Recompile tout
```

## 🚀 Utilisation

```bash
# Avec des nombres séparés
./push_swap 4 67 3 87 23

# Avec une chaîne (votre split gère ça)
./push_swap "4 67 3 87 23"

# Tester le nombre d'opérations
./push_swap 4 67 3 87 23 | wc -l
```

## 📊 Performances de votre algorithme

Votre implémentation utilise :
- **Chunks de 4** pour < 100 éléments
- **Chunks de 8** pour ≥ 100 éléments
- **Calcul du coût minimal** à chaque itération
- **Optimisation rr/rrr** pour les rotations communes

### Résultats attendus

| Taille | Opérations moyennes |
|--------|-------------------|
| 3 éléments | 0-2 opérations |
| 5 éléments | ~7-12 opérations |
| 100 éléments | ~700 opérations |
| 500 éléments | ~5500 opérations |

## 🧪 Tests

### Tests basiques

```bash
# 3 nombres
./push_swap 2 1 3

# 5 nombres
./push_swap 5 4 3 2 1

# Liste déjà triée (aucune sortie)
./push_swap 1 2 3 4 5
```

### Tests avec générateur

```bash
# 100 nombres aléatoires
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

# Vérifier avec checker
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

### Tests d'erreurs

```bash
# Nombre invalide
./push_swap 1 2 abc
# Sortie : "Error"

# Doublon
./push_swap 1 2 2 3
# Sortie : "Error"

# Dépassement INT
./push_swap 2147483648
# Sortie : "Error"
```

## 🎯 Points techniques de votre implémentation

### 1. Système de position

Votre code assigne une **position relative** (rang) à chaque nombre :
- Le plus petit = position 1
- Le 2ème plus petit = position 2
- etc.

Cela simplifie les comparaisons.

### 2. Calcul intelligent des rotations

```c
int count_op(t_list *stack, int position)
{
    int i = get_index(stack, position);
    int size = stack_size(stack);
    
    if (i < size / 2)
        ops = i;           // ra (rotation normale)
    else
        ops = (i - size);  // rra (reverse, nombre négatif)
    
    return ops;
}
```

**Astuce :** Les valeurs négatives indiquent `rra`, les positives `ra`.

### 3. Optimisation des rotations communes

```c
int total_ops(int ops_a, int ops_b)
{
    ops_a = ft_ntp(ops_a);  // Valeur absolue
    ops_b = ft_ntp(ops_b);
    
    if (ops_a == ops_b)
        total_ops = (ops_b + ops_a) / 2;  // Utilise rr/rrr
    else if (ops_a > ops_b)
        total_ops = ops_a - ops_b;
    else
        total_ops = ops_b - ops_a;
    
    return total_ops + 1;
}
```

### 4. Adaptation selon la taille

Votre code s'adapte automatiquement :
- **< 100 éléments** : chunks de 4
- **≥ 100 éléments** : chunks de 8 (moins de calculs)

## 🔗 Dépendances

- **ft_printf** : Intégré dans le projet (dossier `ft_printf/`)

## 📝 Norminette

Le code respecte la norme de 42 :
- ✅ Maximum 25 lignes par fonction
- ✅ Gestion propre de la mémoire
- ✅ Pas de variables après instructions

## 👨‍💻 Auteur

**Arnaud Herman** (@arnaudherman)  
École 42 Lausanne  
Projet réalisé en 2023

---

*"The cheapest operation is often the smartest one."* 📚✨
