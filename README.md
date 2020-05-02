# Libft
*Premier projet de 42 ayant pour but de recoder un certain nombre de fonctions
de la librairie C standard, ainsi que d'autres fonctions utilitaires.*

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


## Get_next_line
Retourne une ligne lue depuis un file descriptor (gestion de plusieurs file descriptors simultanément).


## Ft_printf
Reproduction de la fonction printf
* Conversion gérés: CcSspDdiUuOoXxFfp%*.
* Ajout de la conversion B/b pour base binaire.
* Flags gérés: h,hh,l,ll,L,z,j,#,0,-,+
* Precision et taille minimum de champs.
* Fonctions ft_dprintf et ft_asprintf.


## Partie Personnelle
### #String Vectors
Un vecteur est ici un conteneur qui peut contenir une string.
Toutes les allocations, redimensionnements et optimisations de la taille du conteneur
sont gérés en interne par les fonctions elle-mêmes.
Ils sont definis par la structure suivante:

    typedef struct	s_vector
    {
	      char      *str;
          size_t    len;
	      size_t    size;
	      size_t    scale;
    }               t_vector;

#### vct_add
> Ajoute un caractère à la fin du vecteur.
#### vct_addcharat
> Remplace un caractère à l'indice donné.
#### vct_addnstr
> Ajoute une string sur n octets à la fin du vecteur.
#### vct_addstr
> Ajoute une string à la fin du vecteur.
#### vct_addstrat
> Ajoute une string à l'indice donné en remplaçant les caractères présents si ceux-ci existent.
#### vct_apply
> Applique une fonction de test (ex: is_upper) ou de modification (to_upper) à un vecteur.
#### vct_cat
> Concatène deux vecteurs.
#### vct_cdup
> Duplique un vecteur jusqu'à un caractère donné.
#### vct_charat
> Renvoie le caractère de l'indice donné.
#### vct_chr
> Renvoie l'indice de la première occurence du caractère recherché et -1 si celui-ci n'a pas été trouvé.
#### vct_clear
> Met tout les octets de str à '\0' et reinitialise len à 0.
#### vct_clen
> Renvoie la taille de la chaine contenue dans un vecteur jusqu'au caractère c.
#### vct_countchar
> Renvoie le nombre d'occurence d'un caractère dans un vecteur.
#### vct_countstr
> Renvoie le nombre d'occurence d'une caine de charactère dans un vecteur.
#### vct_cpy
> Copie le contenu d'un vecteur dans un autre.
#### vct_creadline
> Lis jusqu'à 'c' sur un fd et renvoie velle-ci via la chaine contenu dans le vecteur passé en paramètre.
#### vct_cut
> Supprime le dernier caractère d'un vecteur.
#### vct_cutfrom
> Supprime les n derniers caractères d'un vecteur.
#### vct_del
> Supprime un vecteur.
#### vct_delchar
> Supprime un charactere.
#### vct_dup
> Duplique un vecteur.
#### vct_dupstr
> Renvoie une copie de la chaine de caractères contenue dans un vecteur.
#### vct_endby
> Renvoie 1 si le vecteur se termine par la chaine str, sinon 0.
#### vct_eq
> Renvoie 1 si les chaines de caractères contenues dans les deux vecteurs sont identiques, sinon 0.
#### vct_extend
> Réalloue str à une taille donnée et recopie le contenu initialement présent dans la nouvelle chaine.
#### vct_fillback
> Ajoute n fois le caractère c à la fin du vecteur.
#### vct_fillfront
> Ajoute n fois le caractère c au début du vecteur.
#### vct_fullof
> Verifie que le vecteur est rempli uniquement de charactere du charset.
#### vct_getcharat
> Renvoie le nième caractère d'un vecteur.
#### vct_getfirstchar
> Renvoie le premier caractère d'un vecteur.
#### vct_getlastchar
> Renvoie le dernier caractère d'un vecteur.
#### vct_getstr
> Renvoie un pointeur sur la chaine de caractères contenue dans un vecteur.
#### vct_join
> Joins les chaines contenues dans deux vecteurs dans un nouveau vecteur.
#### vct_joinfree
> Joins les chaines contenues dans deux vecteurs dans un nouveau vecteur et libère l'un, l'autre ou les deux.
#### vct_len
> Renvoie la taille de la chaine contenue dans un vecteur.
#### vct_ndup
> Duplique un vecteur sur au maximum n octets.
#### vct_neq
> Renvoie 1 si les chaines de caractères contenues dans les deux vecteurs sont identiques sur n octets, sinon 0.
#### vct_new
> Initialise un nouveau vecteur de la taille passée en paramètre.
> Si la taille est de 0, la taille sera réinitialisée à la valeur définie par VCT_DEFAULT_SIZE.
#### vct_newstr
> Initialise un nouveau vecteur avec la chaine passée en paramètre.
#### vct_nlen
> Renvoie la taille de la chaine contenue dans un vecteur sur un maximum n octets.
#### vct_optimize
> Optimise la mémoire d'un vecteur en le réallouant si le conteneur est plus de
> 3 fois plus grand que la chaine contenue par celui-ci.
#### vct_pop
> Supprime le premier charactère d'un vecteur.
#### vct_popfrom
> Supprime les n premiers charactères d'un vecteur.
#### vct_print
> Affiche un vecteur sur 'len' octets.
#### vct_print_fd
> Affiche un vecteur sur 'len' octets sur un fd donné.
#### vct_printendl
> Affiche un vecteur sur 'len' octets et ajoute un '\n'.
#### vct_printendl_fd
> Affiche un vecteur sur 'len' octets et ajoute un '\n' sur un fd donné.
#### vct_push
> Ajoute un caractère au début du vecteur.
#### vct_pushstr
> Ajoute une chaine de caractère au début du vecteur.
#### vct_readline
> Lis une ligne sur un fd et renvoie velle-ci via la chaine contenu dans le vecteur passé en paramètre.
#### vct_replacechar
> Remplace toutes les occurences du caractère 'to_replace' d'un vecteur par le caractère 'by'.
#### vct_replacestr
> Remplace toutes les occurences de la chaine de caractère 'to_replace' d'un vecteur par la chaine de caractère 'by'.
#### vct_reset
> Réinitialise un vecteur à ses valeurs aux valeurs par défaut définies dans ft_vector.h.
#### vct_split
> Divise la chaine de caractère contenue dans le vecteur via les caractères présents dans str
> et renvoie à chaque appel de strsplit la prochaine partie divisée  dans un nouveau vecteur
> tant que celle-ci est rappelé avec le même vecteur ou NULL. Si le vecteur initial change,
> la division se fera sur ce nouveau vecteur.
> Le flag EACH_SEP permet d'obtenir chaque séparateur dans un vecteur distinct et ALL_SEP,
> tout les séparateurs qui se suivent dans le même vecteur.
#### vct_splitchr
> Divise le vecteur initial sur la première occurence du caractère c (celui-ci non inclus).
> La première partie est renvoyé dans un nouveau vecteur tandis que la seconde
> est copiée dans le vecteur initial en écrasant les données initialement présentes. 
#### vct_startby
> Renvoie 1 si le vecteur commence par la chaine str, sinon 0.
#### vct_str
> Renvoie l'indice de la première occurence de la chaine de caractère recherchée et -1 si celle-ci n'a pas été trouvée.
#### vct_strcheck
> Applique une fonction de test (ex: str_is_uppercase) à un vecteur.
#### vct_sub
> Renvoie un nouveau vecteur étant la suvdivision d'un autre.
#### vct_trim
> Supprime chaque occurence des caractères présents dans str.
#### vct_trimfront
> Supprime toutes les occurences des caractères présents au debut de str.
#### vct_wordsplit
> Divise la chaine de caractère contenue dans le vecteur de la même façon que vct_split
> mais la chaine passée en paramètre est strictement le délimiteur.

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
>  Convertit la chaine str en entier dans la base donnée.
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
#### ft_abs
> Renvoie la valeur absolue d'un nombre.
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
> Effectue un strsplit sur '\n', '\t' et ' '.
