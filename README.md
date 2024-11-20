# class_db
A simple skeleton code in C for a database

Voici un **README.md** rédigé de manière plus formelle, comme un rendu de projet :

---

### **README.md**

```markdown
# Mini Base de Données en C

## **Introduction**

Ce projet a pour objectif la création d'une base de données rudimentaire en langage C, avec un moteur de gestion de données utilisant un arbre binaire pour le stockage en mémoire. L'application prend en charge des commandes SQL simples, telles que `INSERT` et `SELECT`, et implémente un mécanisme de persistance des données sur disque.

---

## **Fonctionnalités principales**

Le programme permet de gérer une base de données simple avec les fonctionnalités suivantes :
- **INSERT** : Ajoute des données dans la base de données.
- **SELECT** : Récupère et affiche toutes les données stockées dans la base.
- **.exit** : Quitte l'application proprement.

Le projet inclut également :
- L'utilisation d'un **arbre binaire** pour organiser les données en mémoire, ce qui permet des insertions et recherches efficaces.
- Un mécanisme de **persistance sur disque**, permettant de sauvegarder les données entre les exécutions.
- Une **interface en ligne de commande** permettant à l'utilisateur de saisir des requêtes SQL simples.

---

## **Organisation du code**

Le code du projet est structuré comme suit :

```
📁 projet
├── 📁 src
│   ├── btree.c         # Gestion des arbres binaires pour stocker les données
│   ├── btree.h         # Interface de l'arbre binaire
│   ├── table.c         # Gestion des tables et des lignes de données
│   ├── table.h         # Interface pour la gestion des tables
│   ├── persistence.c   # Sauvegarde et lecture des données sur disque
│   ├── persistence.h   # Interface pour la persistance des données
│   └── main.c          # Point d'entrée et gestion de l'interface utilisateur
├── 📁 tests
│   └── test.c          # Tests unitaires pour valider le fonctionnement des composants
├── Makefile            # Automatisation de la compilation
└── README.md           # Documentation du projet
```

- **`btree.c` et `btree.h`** : Ces fichiers contiennent l'implémentation de l'arbre binaire, une structure de données efficace pour organiser et rechercher des données.
- **`table.c` et `table.h`** : Ces fichiers définissent la structure des lignes et des tables, qui organisent les données à insérer dans la base.
- **`persistence.c` et `persistence.h`** : La persistance des données sur disque est gérée par ces fichiers, permettant la sauvegarde et la récupération des données entre les sessions.

---

## **Prérequis**

Le projet nécessite les outils suivants pour être compilé et exécuté :
- **GCC** : Un compilateur C pour compiler le code source.
- **Make** : Utilisé pour automatiser le processus de compilation.
- Un environnement Unix (Linux ou macOS) ou Windows avec **MinGW** pour compiler sous Windows.

---

## **Instructions de Compilation**

Pour compiler et exécuter le projet, suivez les étapes suivantes :

1. Clonez le repository :
   ```bash
   git clone https://github.com/Utilisateur/nom-du-projet.git
   cd nom-du-projet
   ```

2. Compilez le projet en utilisant `make` :
   ```bash
   make
   ```

   Cela générera un exécutable appelé `db`.

---

## **Utilisation**

Pour démarrer l'application, exécutez l'exécutable `db` :

```bash
./db
```

### **Exemples de commandes SQL** :

1. **INSERT** : Ajouter des données dans la base de données.
   ```
   db > insert
   Executed.
   ```

2. **SELECT** : Afficher toutes les données stockées dans la base.
   ```
   db > select
   1 | John Doe | johndoe@example.com
   2 | Jane Smith | janesmith@example.com
   ```

3. **.exit** : Quitter le programme.
   ```
   db > .exit
   ```

---

## **Tests**

Des tests unitaires sont inclus pour garantir la robustesse du projet. Pour exécuter les tests :

1. Compilez les tests avec la commande :
   ```bash
   make run-test
   ```

2. Lancez les tests :
   ```bash
   ./test
   ```

Ces tests valident les fonctionnalités principales du projet, comme l'ajout et la récupération des données, ainsi que la gestion de l'arbre binaire.

---

## **Outils et Technologies Utilisées**

### **Outils de détection de bogues** :
- **Valgrind** : Pour détecter les fuites de mémoire et les erreurs d'accès mémoire.
- **Sanitizers (ASAN/UBSAN)** : Utilisés pour détecter les erreurs liées à la mémoire et aux comportements indéfinis durant l'exécution du programme.
- **Fuzzing (AFL++)** : Employé pour tester le programme avec des entrées aléatoires afin de découvrir des failles potentielles.

### **Structures de données** :
- **Arbre binaire** : Permet une gestion efficace des insertions, des recherches et des suppressions.
- **Fichiers binaires** : Utilisés pour la persistance des données, assurant que les informations ne soient pas perdues à la fin de l'exécution.

---

## **Améliorations Futures**

Pour améliorer cette base de données, voici quelques idées pour des fonctionnalités futures :
1. Ajout de nouvelles commandes SQL :
   - **DELETE** pour supprimer des lignes spécifiques.
   - **UPDATE** pour modifier des données existantes.
2. Implémentation d'un **équilibrage automatique** de l'arbre binaire, afin d'améliorer les performances des opérations.
3. Gestion plus fine des transactions et des verrouillages pour permettre un fonctionnement plus robuste dans des systèmes multi-utilisateurs.
4. Optimisation de la persistance avec un format de fichier plus adapté.
5. Développement d'une API ou d'une interface graphique pour faciliter l'interaction avec la base de données.

