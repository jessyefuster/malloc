# malloc
42 malloc project


# Functions

*malloc*
--
``
void  *malloc(size_t size);
``
La fonction malloc() alloue "size" octets de mémoire et retourne un pointeur sur la mémoire allouée.
En cas d’erreur, malloc() retourne un pointeur NULL

*realloc*
--
``
void  *realloc(void *ptr, size_t size);
``
La fonction realloc() essaye de modifier la taille de l’alloction pointée par "ptr" à "size" octets, et retourne "ptr". Si il n’y a pas assez de place à l’emplacement mémoire pointé par "ptr", realloc() crée une nouvelle allocation, y copie autant de données de l’ancienne allocation que possible dans la limite de la taille de la nouvelle allocation, libère l’ancienne allocation et retourne un pointeur sur cette nouvelle allocation.
En cas d’erreur, realloc() retourne un pointeur NULL

*free*
--
``
void  free(void *ptr);
``
La fonction free() libère l’allocation de la mémoire pointée par "ptr". Si "ptr" vaut NULL, free() ne fait rien
