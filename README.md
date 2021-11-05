# AbstractVM

## Compilation

### Pour une compilation simple
Vous pouvez faire cette commande pour compiler le projet :

```bash
make -j 8
```
### Pour une re-compilation
Vous pouvez faire cette commande pour compiler le projet :

```bash
make re -j 8
```

### Pour nettoyer les fichiers
```bash
make fclean
```

### Pour une compilation pour les units_tests

#### units_tests uniquement
```bash
make fclean
make tests_run -j 8
```

#### units_tests avec gcovr et sortie dans un fichier html
```bash
make fclean
make coverage_html_run -j 8
```

#### units_tests avec gcovr pour le coverage uniquement
```bash
make fclean
make coverage_run -j 8
```

#### units_tests avec gcovr pour les branch uniquement
```bash
make fclean
make branches_run -j 8
```

## Contribution
Les contributions sont ouvertes :P

## License
[MIT](https://choosealicense.com/licenses/mit/) 
