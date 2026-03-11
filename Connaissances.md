# CONNAISSANCES POUR GNL :
## Static Variable :
Garde sa valeur entre les appels de fonction.

### Ex : sans static :
{\
  int count = 0;   _créé à chaque appel_\
  count++;\
  printf("%d", count);\
}\
int main()\
{\
  compteur();   _affiche 1_\
  compteur();   _affiche 1_\
}\
=> Count est détruit à la fin de chaque appel.

### Ex : avec static :
{\
  static int count = 0;   _initialisée 1 seule fois_\
  count++;\
  printf("%d", count);\
}\
int main()\
{\
  compteur();   _affiche 1_\
  compteur();   _affiche 2_\
}\
=> La variable count survit entre les appels.

## FD (File Descriptor) :
C'est un numéro qui identifie un "canal" de lecture/écriture.\
**0** stdin entrée standard (clavier)\
**1** stdout sortie standard (terminal)\
**2** stdout erreur standard (terminal)\

- read()
- open()
- close()

fd = open("test.txt", O_RDONLY);

- O_RDONLY = lecture seule,
- O_WRONLY = écriture seule,
- O_RDWR = lecture et écriture,
- O_TRUNC = ouverture d'un fichier en mode tronqué,
- O_APPEND = ouverture du fichier en mode ajout,
- O_CREAT = crée le fichier si il n'existe pas.

Toujours fermer le FD avec close : **close (fd);**

ssise_t bytes_read\
bytes_read = read(fd, buffer, BUFFER_SIZE)\
Toujours vérif la valeur de read :
- supérieur à 0 = nb d'octets lus
- 0 = fin de fichier (EOF)
- -1 = erreur

Lit buffer_size octet dans fd et le copie dans buffer.\
Read ne rajoute jamais de \0 automatiquement.

### Size_t VS Ssize_t :
### Size_t :
- unsigned
- utilisé pour des tailles et indices
- ne peut pas etre négatif
- défini dans <stddef.h>, <stdlib.h>, <string.h>
### Ssize_t :
- signed
- utilisé pour des valeurs de retour qui peuvent etre négatives
- peut représenter une erreur (-1)
- défini dans <unistd.h>

## Buffer :
C'est une zone de mémoire temporaire utilisée pour stocker des données pendant leur traitement.

### Analogies :
- un sceau qui reçoit de l'eau (données) avant de la verser ailleurs
- un carton de déménagement
- un bus qui attend d'etre rempli avant de partir

En C c'est juste un tableau qui sert de zone de stockage temporaire.

### Pq un buffer dans GNL ?
On lit par blocks de BUFFER_SIZE octets, le buffer stocke ces blocks temporairement.\
Sans buffer on lirait caractère par caractère -> LENT.\
Avec buffer on lit blocs par blocs -> efficace, moins d'appels système.

Faire un appel de  40 octets est + rapide que 0 appels de 1 octet.

### Types de buffer :
- buffer sur la stack (local) -> détruit à la fin de la fonction,
- buffer sur le heap (dynamique) -> existe jusqu'à free,
- buffer statique -> persiste entre les appels.

Le mot vient de l'anglais "to buffer" = amortir, tamponner.

Ex :
- vidéo en streaming : le buffer charge les données en avance,
- clavier : quand on tape vite, les caractères vont dans un buffer,
- imprimante : les données à imprimer attendent dans un buffer.

### En résumé :
C'est une zone de mémoire temporaire qui stocke des données temporairement pendant leur traitement.\
Cela améliore les performances.\
En C : char buffer[taille].\
Risque d'overflow si on écrit + que la taille.
