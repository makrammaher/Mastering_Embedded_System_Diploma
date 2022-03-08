echo '-------------------------------------------------------------------------'
echo '                   Building c project powershell script                  '
echo '-------------------------------------------------------------------------'
echo ''
echo '>> Preprocessing phase'
echo '>> Creating .i files'
echo ''

gcc -E -Wall -std=c89 -ansi main.c -o main.i

echo ''
echo '>> Compiling phase'
echo '>> Creating .s files'
echo ''

gcc -S -Wall -std=c89 -ansi main.c -o main.s

echo ''
echo '>> Assembling phase'
echo '>> Creating .o files'
echo ''

gcc -c -Wall -std=c89 -ansi main.c -o main.o

echo ''
echo '>> linking phase'
echo '>> Creating .exe file'
echo ''

gcc -Wall -std=c89 -ansi main.c -o main.exe

echo ''
echo '>> Running Phase'
echo '>> Execute .exe file'
echo ''


echo '-------------------------------------------------------------------------'
echo '                    Running c project powershell script                  '
echo '-------------------------------------------------------------------------'
echo ''
./main.exe
echo ''
echo ''
echo '>> Made by Makram Maher Makram'
echo '-------------------------------------------------------------------------'
echo '                         ------<< END >>------                           '
echo '-------------------------------------------------------------------------'
