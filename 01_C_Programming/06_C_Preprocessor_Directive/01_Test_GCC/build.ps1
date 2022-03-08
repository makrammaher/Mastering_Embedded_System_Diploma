
echo 'Building project using makrammaher build script now'
echo 'preprocessing phase'
echo 'creating .i files'
gcc -E main.c -o main.i
echo 'combiling phase'
echo 'creating .s files'
gcc -S main.c -o main.s
echo 'full combilling phase'
echo 'creating .exe file'
gcc main.c -o main.exe

echo '---------------------------------------------------------------------------'
echo '-------------------------------RUN Program---------------------------------'
echo '---------------------------------------------------------------------------'

.\main.exe

echo '---------------------------------------------------------------------------'
