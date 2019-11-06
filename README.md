# libft_42
Premier projet de 42 ayant pour but de recoder un certain nombre de fonctions de la librairie C standard, ainsi que d'autres fonctions utilitaires.

## Partie 1
### Reproduction de fonctions de la lib C :
* ft_memset
* ft_bzero
* ft_memcpy
* ft_memccpy
* ft_memmove
* ft_memchr
* ft_memcmp
* ft_strlen
* ft_strdup
* ft_strcpy
* ft_strncpy
* ft_strcat
* ft_strncat
* ft_strlcat
* ft_strchr
* ft_strrchr
* ft_strstr
* ft_strnstr
* ft_strcmp
* ft_strncmp
* ft_atoi
* ft_isalpha
* ft_isdigit
* ft_isalnum
* ft_isascii
* ft_isprint
* ft_toupper
* ft_tolower

## Partie 2
#### ft_memalloc
> Alloue (avec malloc(3)) et retourne une zone de mémoire
> “fraiche”. La mémoire allouée est initialisée à 0. Si l’allocation
> échoue, la fonction renvoie NULL.
#### ft_memdel
> Prend en paramètre l’adresse d’un pointeur dont la zone pointée doit être libérée 
> avec free(3), puis le pointeur est mis à NULL.
#### ft_strnew
> Alloue (avec malloc(3)) et retourne une chaîne de caractère
> “fraiche” terminée par un ’\0’. Chaque caractère de la chaîne
> est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie NULL.
#### ft_strdel
> Prend en paramètre l’adresse d’une chaîne de caractères qui
> doit être libérée avec free(3) et son pointeur mis à NULL.
#### ft_strclr
> Assigne la valeur ’\0’ à tous les caractères de la chaîne passée
> en paramètre.
#### ft_striter
> Applique la fonction f à chaque caractère de la chaîne de
> caractères passée en paramètre. Chaque caractère est passé
> par adresse à la fonction f afin de pouvoir être modifié si
> nécessaire.
#### ft_striteri
> Applique la fonction f à chaque caractère de la chaîne de
> caractères passée en paramètre en précisant son index en premier argument.
> Chaque caractère est passé par adresse à la
> fonction f afin de pouvoir être modifié si nécessaire.
#### ft_strmap
> Applique la fonction f à chaque caractère de la chaîne de caractères
> passée en paramètre pour créer une nouvelle chaîne
> “fraiche” (avec malloc(3)) résultant des applications successives de f.
#### ft_strmapi
> Applique la fonction f à chaque caractère de la chaîne de
> caractères passée en paramètre en précisant son index pour
> créer une nouvelle chaîne “fraiche” (avec malloc(3)) résultant
> des applications successives de f.
#### ft_strequ
> Compare lexicographiquement s1 et s2. Si les deux chaînes
> sont égales, la fonction retourne 1, ou 0 sinon.
#### ft_strnequ
> Compare lexicographiquement s1 et s2 jusqu’à n caractères
> maximum ou bien qu’un ’\0’ ait été rencontré. Si les deux
> chaînes sont égales, la fonction retourne 1, ou 0 sinon.
#### ft_strsub
> Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
> tronçon de la chaîne de caractères passée en paramètre. Le
> tronçon commence à l’index start et a pour longueur len. Si
> start et len ne désignent pas un tronçon de chaîne valide,
> le comportement est indéterminé. Si l’allocation échoue, la
> fonction renvoie NULL.
#### ft_strjoin
> Alloue (avec malloc(3)) et retourne une chaîne de caractères
> “fraiche” terminée par un ’\0’ résultant de la concaténation
> de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL.
#### ft_strtrim
> Alloue (avec malloc(3)) et retourne une copie de la chaîne
> passée en paramètre sans les espaces blancs au debut et à la
> fin de cette chaîne. On considère comme espaces blancs les
> caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
> blancs au début ou à la fin, la fonction renvoie une copie de
> s. Si l’allocation echoue, la fonction renvoie NULL.
#### ft_strsplit
> Alloue (avec malloc(3)) et retourne un tableau de chaînes de
> caractères “fraiches” (toutes terminées par un ’\0’, le tableau
> également donc) résultant de la découpe de s selon le caractère
> c. Si l’allocation echoue, la fonction retourne NULL.
#### ft_itoa
> Alloue (avec malloc(3)) et retourne une chaîne de caractères
> “fraiche” terminée par un ’\0’ représentant l’entier n passé
> en paramètre. Les nombres négatifs doivent être gérés.
> Si l’allocation échoue, la fonction renvoie NULL.
#### ft_putchar
> Affiche le caractère c sur la sortie standard.
#### ft_putstr
> Affiche la chaîne s sur la sortie standard.
#### ft_putendl
> Affiche la chaîne s sur la sortie standard suivi d’un ’\n’.
#### ft_putnbr
> Affiche l’entier n sur la sortie standard.
#### ft_putchar_fd
> Ecrit le caractère c sur le descripteur de fichier fd.
#### ft_putstr_fd
> Ecrit la chaîne s sur le descripteur de fichier fd.
#### ft_putendl_fd
> Ecrit la chaîne s sur le descripteur de fichier fd suivi d’un ’\n’.
#### ft_putnbr_fd
> Ecrit l’entier n sur le descripteur de fichier fd.

## Partie Bonus
#### ft_lstnew
> Alloue (avec malloc(3)) et retourne un maillon “frais”. Les
> champs content et content_size du nouveau maillon sont initialisés par
> copie des paramètres de la fonction. Si le paramètre content est nul,
> le champs content est initialisé à NULL et le champs content_size est
> initialisé à 0 quelque soit la valeur du paramètre content_size. Le champ next
> est initialisé à NULL. Si l’allocation échoue, la fonction renvoie NULL.
#### ft_lstdelone
> Prend en paramètre l’adresse d’un pointeur sur un maillon et
> libère la mémoire du contenu de ce maillon avec la fonction
> del passée en paramètre puis libère la mémoire du maillon
> en lui même avec free(3). La mémoire du champ next ne
> doit en aucun cas être libérée. Pour terminer, le pointeur sur
> le maillon maintenant libéré doit être mis à NULL (de manière
> similaire à la fonction ft_memdel de la partie obligatoire).
#### ft_lstdel
> Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la mémoire
> de ce maillon et celle de tous ses successeurs l’un après l’autre avec del et free(3).
> Pour terminer, le pointeur sur le premier maillon maintenant libéré doit être
> mis à NULL (de manière similaire à la fonction ft_memdel de la partie obligatoire).
#### ft_lstadd
> Ajoute l’élément new en tête de la liste.
#### ft_lstiter
> Parcourt la liste lst en appliquant à chaque maillon la fonction f.
#### ft_lstmap
> Parcourt la liste lst en appliquant à chaque maillon la fonction f et crée
> une nouvelle liste “fraiche” avec malloc(3) résultant des applications successives.
> Si une allocation échoue, la fonction renvoie NULL.

## get_next_line
> Retourne une ligne lue depuis un file descriptor (gestion de plusieurs file descriptors simultanément).
## ft_printf
> Reproduction de la fonction printf
> * Conversion gérés: CcSspDdiUuOoXxFfp%*.
> * Ajout de la conversion B/b pour base binaire.
> * Flags gérés: h,hh,l,ll,L,z,j,#,0,-,+
> * Precision et taille minimum de champs.
> * Fonctions ft_dprintf et ft_asprintf.

## Partie Personnelle
### #String Vectors
#### vct_add
#### vct_addcharat
#### vct_addnstr
#### vct_addstr
#### vct_addstrat
#### vct_apply
#### vct_cat
#### vct_cdup
#### vct_charat
#### vct_chr
#### vct_clear
#### vct_clen
#### vct_countchar
#### vct_countstr
#### vct_cpy
#### vct_cut
#### vct_cutfrom
#### vct_del
#### vct_dup
#### vct_dupstr
#### vct_endby
#### vct_eq
#### vct_extend
#### vct_fillback
#### vct_fillfront
#### vct_getcharat
#### vct_getfirstchar
#### vct_getlastchar
#### vct_getstr
#### vct_join
#### vct_joinfree
#### vct_len
#### vct_ndup
#### vct_neq
#### vct_new
#### vct_newstr
#### vct_nlen
#### vct_optimize
#### vct_pop
#### vct_popfrom
#### vct_print
#### vct_print_fd
#### vct_printendl
#### vct_printendl_fd
#### vct_push
#### vct_pushstr
#### vct_readline
#### vct_replacechar
#### vct_replacestr
#### vct_reset
#### vct_split
#### vct_splitchr
#### vct_startby
#### vct_str
#### vct_strcheck
#### vct_sub
#### vct_trim
#### vct_wordsplit

### #Autres Fonctions
Reproduction de fonctions de la lib C :
* ft_iscntrl
* ft_isblank
* ft_isgraph
* ft_isspace
* ft_xdigit
* ft_strcasecmp
* ft_strcasestr
* ft_atol
* ft_strndup
* ft_strncasecmp

#### ft_atoi_base
>  Convertit la chaine str en entier dans la base donné.
#### ft_itoa_base
> Alloue (avec malloc(3)) et retourne une chaîne de caractères
> “fraiche” terminée par un ’\0’ représentant l’entier value passé
> en paramètre dans la base donné. Les nombres négatifs doivent être gérés.
> Si l’allocation échoue, la fonction renvoie NULL.
#### ft_lst_mergesort
> Effectue un merge sort sur lst avec pour condition la fonction test passé en paramètre. 
#### ft_lstadd_back
> Ajoute un élément à la fin de la liste.
#### ft_lstdelnode
> Supprime le maillon de la liste qui a pour donnée la même adresse que data.
#### ft_lstlast
> Renvoie le dernier élément de la liste.
#### ft_lstnew_nomalloc
> Créer un nouvel élément en copiant le pointeur 'content' et non ce qui est pointé.
#### ft_lstpop
> Supprime le premier maillon de la liste.
#### ft_lstsize
> Renvoie la taille de la liste.
#### ft_factorial
> Renvoie la factorielle du nombre passé en paramètre.
#### ft_pow
> Renvoie le nombre n à la puissance p.
#### ft_sqrt
> Renvoie la racine carré du nombre passé en paramètre.
#### ft_swap_bits
> Inverse les 4 premiers et les 4 derniers bits d'un octet.
#### ft_inverse_bits
> Inverse tout les bits d'un octet.
#### ft_read_all
> Renvoie l'integralité d'un fichier.
#### ft_swap
> Intervertit deux entiers. 
#### ft_print_int_bits
> Affiche chaque bit d'un int.
#### ft_print_inttab
> Affiche un tableau d'int.
#### ft_print_strtab
> Affiche un tableau de strings.
#### ft_putnbr_base
> Affiche un entier dans une base donnée.
#### ft_bubblesort_integer
> Effectue un bubble sort sur un tableau d'entiers.
#### ft_bubblesort_strtab
> Effectue un bubble sort sur un tableau de strings.
#### ft_insertsort_integer
> Effectue un insertion sort sur un tableau d'entiers.
#### ft_insertsort_strtab
> Effectue un insertion sort sur un tableau de strings.
#### ft_free_tab_str
> Libère un tableau de strings.
#### ft_str_is_lowercase
> Verifie si la chaine n'est composé que de minuscules.
#### ft_str_is_uppercase
> Verifie si la chaine n'est composé que de majuscules.
#### ft_str_is_numeric
> Verifie si la chaine n'est composé que de nombres.
#### ft_strcheck
> Applique une fonction de test de char à une string.
#### ft_strcdup
> Duplique une chaine jusqu'à un caractère donné.
#### ft_strclen
> Renvoie la taille d'une chaine jusqu'à un caractère donné.
#### ft_strjoinfree
> Effectur un strjoin en effectuant un free sur l'une, l'autre ou les deux strings.
#### ft_strlowcase
> Passe une chaine en minuscule.
#### ft_strupcase
> Passe une chaine en majuscule.
#### ft_strnlen
> Renvoie la taille d'une chaine d'une taille maximum de n.
#### ft_strsplit_whitespaces
> Effectue un strsplit sur '\n', '\t' et ' ',
