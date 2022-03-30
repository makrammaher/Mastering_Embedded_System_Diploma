echo '-------------------------------------------------------------------------'
echo '       ------<< Creating new c project powershell script >>------        '
echo '-------------------------------------------------------------------------'
echo ''
$projectname = read-host 'Enter the name of the new project'
echo ''
echo '>> Creating new folder'
New-Item -ItemType Directory $projectname
echo ''
echo '>> Copying build_S to the new folder'
Copy-Item .\build_S.ps1 .\$projectname
echo ''
echo '>> Set-loction to the new folder'
Set-Location $projectname
echo ''
echo '>> Create main.c file'
new-item main.c
echo ''
echo '>> Initialize main.c file'
"/*" | out-file main.c -Encoding utf8
" *           File: main.c" | out-file main.c -Append -Encoding utf8
$datetime = Get-Date -Format "dddd dd/MM/yyyy HH:mm"
[System.String]::Concat(" *     Created on: ",$datetime)| out-file main.c -Append -Encoding utf8
" *         Author: Makram Maher Makram" | out-file main.c -Append -Encoding utf8
" *        Subject: " | out-file main.c -Append -Encoding utf8
" *" | out-file main.c -Append -Encoding utf8
" *" | out-file main.c -Append -Encoding utf8
" */" | out-file main.c -Append -Encoding utf8
""| out-file main.c -Append -Encoding utf8
"/* Includes files */"| out-file main.c -Append -Encoding utf8
"#include<stdio.h>"| out-file main.c -Append -Encoding utf8
""| out-file main.c -Append -Encoding utf8
"/* main function */"| out-file main.c -Append -Encoding utf8
"int main(void)"| out-file main.c -Append -Encoding utf8
"{"| out-file main.c -Append -Encoding utf8
"   "| out-file main.c -Append -Encoding utf8
"   return 0;"| out-file main.c -Append -Encoding utf8
"}/* end main */"| out-file main.c -Append -Encoding utf8
echo ''
echo '>> Open Sublime-text Enjoy coding :)'
subl .
echo ''
echo ''
echo '>> Made by Makram Maher Makram'
echo '-------------------------------------------------------------------------'
echo '                         ------<< END >>------                           '
echo '-------------------------------------------------------------------------'