Les options `-L` et `-I` sont utilisées dans un Makefile pour indiquer au compilateur où se trouvent les bibliothèques et les fichiers d'en-tête nécessaires à la compilation de votre projet.

`-L` : l'option `-L` indique au compilateur où se trouvent les bibliothèques statiques ou dynamiques utilisées par votre projet. Elle est généralement suivie du chemin absolu ou relatif vers le répertoire contenant les bibliothèques. Par exemple, si votre projet utilise la bibliothèque libfoo.a située dans le répertoire /usr/local/lib, vous pouvez utiliser l'option -L/usr/local/lib pour indiquer au compilateur où se trouve cette bibliothèque.

`-I` : l'option `-I` indique au compilateur où se trouvent les fichiers d'en-tête utilisés par votre projet. Elle est généralement suivie du chemin absolu ou relatif vers le répertoire contenant les fichiers d'en-tête. Par exemple, si votre projet utilise le fichier d'en-tête foo.h situé dans le répertoire /usr/local/include, vous pouvez utiliser l'option -I/usr/local/include pour indiquer au compilateur où se trouve ce fichier.

Voici un exemple de Makefile qui utilise les options -L et -I :

`CC = gcc`<br/>
`CFLAGS = -Wall -Wextra -Werror`<br/>
`LDFLAGS = -L/usr/local/lib -lfoo`<br/>
`INCLUDES = -I/usr`<br/>