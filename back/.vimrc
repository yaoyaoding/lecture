set number
set shiftwidth=4
set tabstop=4
set softtabstop=4
set mouse=a
"set foldmethod=syntax

filetype plugin indent on

map <F10> : ! gdb --silen %< <CR>
map <F9> : ! g++ -g --std=c++11 -Wall -Wextra -Wconversion % -o %< && size %< <CR>
map <C-F9> :  ! g++ -g -O2 --std=c++11 -Wall -Wextra -Wconversion % -o %< && size %< <CR>
map <F8> : ! ./%< < %<.in <CR>
map <F5> : ! ./%< <CR>
map <F3> : vnew %<.in <CR>
map <F4> : ! gedit % <CR>

map <C-A> <ESC>ggVG
map <C-C> "+y

