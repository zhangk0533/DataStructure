set nocompatible              " 这是必需的，去除VI一致性
filetype off                  " 这是必需的 


" 在此设置运行时路径。即设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/vundle
"
"
" " vundle初始化 
 call vundle#begin()  
"
" " 另一种选择, 指定一个vundle安装插件的路径
" "call vundle#begin('~/some/path/here')
"
"
" " 让vundle管理插件版本,必须。" 这应该始终是第一个
 Plugin 'VundleVim/Vundle.vim'
 Plugin 'Valloric/YouCompleteMe'
 Plugin 'Solarized'
 Plugin 'Syntastic'
"
"
" " 以下范例用来支持不同格式的插件安装.
" " 请将安装插件的命令放在vundle#begin和vundle#end之间.
"
" " Github上的插件
" " 格式为 Plugin '用户名/插件仓库名'
" Plugin 'tpope/vim-fugitive'
"
" " 来自 http://vim-scripts.org/vim/scripts.html 的插件
" " Plugin '插件名称' 实际上是 Plugin 'vim-scripts/插件仓库名'
" 只是此处的用户名可以省略
" Plugin 'L9'
"
" " 由Git支持但不再github上的插件仓库 Plugin 'git clone 后面的地址'
" Plugin 'git://git.wincent.com/command-t.git'
"
" " 本地的Git仓库(例如自己的插件) Plugin 'file:///+本地插件仓库绝对路径'
" Plugin 'file:///home/gmarik/path/to/plugin'
"
" " 插件在仓库的子目录中.
" " 正确指定路径用以设置runtimepath. 以下范例插件在sparkup/vim目录下
" Plugin 'rstacruz/sparkup', {
" 'rtp': 'vim/'
" }
"
" " 安装L9，如果已经安装过这个插件，可利用以下格式避免命名冲突
" Plugin 'ascenator/L9', {
" 'name': 'newL9'
" }
"
"
"  你的所有插件需要在下面这行之前"
 call vundle#end()            " 必须
 filetype plugin indent on    " 必须
" 加载vim自带和插件相应的语法和文件类型相关脚本
"
" " 忽视插件改变缩进,可以使用以下替代:
" "filetype plugin on
" "
"
" " 常用的命令
" " :PluginList       - 列出所有已配置的插件
" " :PluginInstall     - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" " :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" " :PluginClean      - 清除未使用插件,需要确认; 追加 `!`
" 自动批准移除未使用插件

set mouse=a
set tabstop=4
set softtabstop=4
set shiftwidth=4
set autoindent
set cindent
set nu
syntax on
set background=dark
set t_Co=256
colorscheme solarized 
let g:syntastic_check_on_open=1
let g:syntastic_enable_signs=1
set completeopt=longest,menu	"让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
autocmd InsertLeave * if pumvisible() == 0|pclose|endif	"离开插入模式后自动关闭预览窗口
"上下左右键的行为 会显示其他信息
inoremap <expr> <Down>     pumvisible() ? "\<C-n>" : "\<Down>"
inoremap <expr> <Up>       pumvisible() ? "\<C-p>" : "\<Up>"
inoremap <expr> <PageDown> pumvisible() ? "\<PageDown>\<C-p>\<C-n>":"\<PageDown>" 
inoremap <expr> <PageUp>   pumvisible() ? "\<PageUp>\<C-p>\<C-n>" : "\<PageUp>"
set backspace=indent,eol,start

"youcompleteme  默认tab  s-tab 和自动补全冲突
""let g:ycm_key_list_select_completion=['<c-n>']
let g:ycm_key_list_select_completion = ['<Down>']
"let g:ycm_key_list_previous_completion=['<c-p>']
"let g:ycm_key_list_previous_completion = ['<Up>']
"let g:ycm_confirm_extra_conf=0 "关闭加载.ycm_extra_conf.py提示
"
"let g:ycm_collect_identifiers_from_tags_files=1	" 开启 YCM 基于标签引擎
"let g:ycm_min_num_of_chars_for_completion=2	"
"从第2个键入字符就开始罗列匹配项
"let g:ycm_cache_omnifunc=0	" 禁止缓存匹配项,每次都重新生成匹配项
"let g:ycm_seed_identifiers_with_syntax=1	" 语法关键字补全
"nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>	"force recomile with
"syntastic
""nnoremap <leader>lo :lopen<CR>	"open locationlist
"nnoremap <leader>lc :lclose<CR>	"close locationlist
"inoremap <leader><leader> <C-x><C-o>
""在注释输入中也能补全
let g:ycm_complete_in_comments = 1
"在字符串输入中也能补全
let g:ycm_complete_in_strings = 1
""注释和字符串中的文字也会被收入补全
let g:ycm_collect_identifiers_from_comments_and_strings = 0

nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR> " 跳转到定义处


inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap { {<CR>}<Esc>O
autocmd Syntax html,vim inoremap < <lt>><Esc>i| inoremap > <c-r>=ClosePair('>')<CR>
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap } <c-r>=CloseBracket()<CR>
inoremap " <c-r>=QuoteDelim('"')<CR>
inoremap ' <c-r>=QuoteDelim("'")<CR>

function ClosePair(char)
	if getline('.')[col('.') - 1] == a:char
		return "\<Right>"
	else
		return a:char
	endif
endf

function CloseBracket()
	if match(getline(line('.') + 1), '\s*}') < 0
		return "\<CR>}"
	else
		return "\<Esc>j0f}a"
	endif
endf

function QuoteDelim(char)
	let line = getline('.')
	let col = col('.')
	if line[col - 2] == "\\"
		return a:char
	elseif line[col - 1] == a:char
		return "\<Right>"
	else
		return a:char.a:char."\<Esc>i"
	 endif
endf
"gcc编译"
func! CompileGcc()
	exec "w"
	let compilecmd="!gcc "
	let compileflag="-o %< "
	if search("mpi\.h") != 0
		let compilecmd = "!mpicc "
	endif
	if search("glut\.h") != 0
		let compileflag .= " -lglut -lGLU -lGL "
	endif
	if search("cv\.h") != 0
		let compileflag .= " -lcv -lhighgui -lcvaux "
	endif
	if search("omp\.h") != 0
		let compileflag .= " -fopenmp "
	endif
	if search("math\.h") != 0
	    let compileflag .= " -lm "
	endif
	exec compilecmd." % ".compileflag
endfunc

func! CompileGpp()
	exec "w"
	let compilecmd="!g++ "
	let compileflag="-o %< "
	if search("mpi\.h") != 0
		let compilecmd = "!mpic++ "
	endif
	if search("glut\.h") != 0
		let compileflag .= " -lglut -lGLU -lGL "
	endif
	if search("cv\.h") != 0
		let compileflag .= " -lcv -lhighgui -lcvaux "
	endif
	if search("omp\.h") != 0
		let compileflag .= " -fopenmp "
	endif
	if search("math\.h") != 0
		let compileflag .= " -lm "
	endif
	exec compilecmd." % ".compileflag
endfunc

func! CompileCode()
	exec "w"
	if &filetype == "cpp"
		exec "call CompileGpp()"
	elseif &filetype == "c"
		exec "call CompileGcc()"
	elseif &filetype == "python"
		exec "call RunPython()"
	elseif &filetype == "java"
		exec "call CompileJava()"
	endif
endfunc

func! CompileJava()
	exec "!javac %"
endfunc 

func! RunPython()
	exec "!python %"
endfunc

func! RunResult()
	exec "w"
	if search("mpi\.h") != 0
		exec "!mpirun -np 4 ./%<"
	elseif &filetype == "cpp"
		exec "! ./%<"
	elseif &filetype == "c"
		exec "! ./%<"
	elseif &filetype == "python"
		exec "call RunPython"
	elseif &filetype == "java"
		exec "!java %<"
	endif
endfunc

autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
autocmd BufNewFile * normal G 

func SetTitle()     
	if &filetype == 'sh'   
		call setline(1,"\#########################################################################")   
		call append(line("."), "\# File Name: ".expand("%"))   
		call append(line(".")+1, "\# Author: zhangk")   
		call append(line(".")+2, "\# mail: 907144187@qq.com")   
		call append(line(".")+3, "\# Created Time: ".strftime("%c"))   
		call append(line(".")+4, "\#########################################################################")   
		call append(line(".")+5, "\#!/bin/bash")   
		call append(line(".")+6, "")   
	else   
		call setline(1, "/*************************************************************************")   
		call append(line("."), "    > File Name: ".expand("%"))   
		call append(line(".")+1, "    > Author:zhangk ")   
		call append(line(".")+2, "    > Mail: 907144187@qq.com ")   
		call append(line(".")+3, "    > Created Time: ".strftime("%c"))   
		call append(line(".")+4, " ************************************************************************/")   
		call append(line(".")+5, "")  
	endif  
	if &filetype == 'cpp'  
		call append(line(".")+6, "#include<iostream>")  
		call append(line(".")+7, "using namespace std;")  
		call append(line(".")+8, "")  
	endif  
	if &filetype == 'c'  
		call append(line(".")+6, "#include<stdio.h>")  
		call append(line(".")+7, "#include<stdlib.h>")
		call append(line(".")+8, "")  
	endif  
endfunc

map <F5> :call CompileCode()<CR>
imap <F5> <ESC>:call CompileCode()<CR>
vmap <F5> <ESC>:call CompileCode()<CR>
map <F6> :call RunResult()<CR>
