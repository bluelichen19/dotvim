" System vimrc file for MacVim
"
" Maintainer:   Bjorn Winckler <bjorn.winckler@gmail.com>
" Last Change:  Sat Aug 29 2009
"========================================================================================================
"Vundle.vim插件管理配置
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
"Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
"Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
"Plugin 'ascenator/L9', {'name': 'newL9'}
"树形资源管理器
"Plugin 'scrooloose/nerdtree' " file drawer, open with :NERDTreeToggle
"帮助文档
"Plugin 'asins/vimcdoc'
"let helptags=$VIM."/vimfiles/doc"
"set helplang=cn
set langmenu=zh_CN.UTF-8
set helplang=cn
"函数导航
"Plugin 'majutsushi/tagbar'
"power-line
"Plugin 'Lokaltog/vim-powerline'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line



"=====================================Pathogen===================================================================
""
"1\git submodule add https://github.com/vim-airline/vim-airline bundle/vim-airline  目标路径是bundle/自己起一个名字
"2\git add --all git stautus
"3\git commit -m "air-line"
"4\git push origin master
"删除
"git rm -r --cached /Users/BLUE/.vim/bundle/Vundle.vim
"重装
"git submodule init
"git submodule update
""


" 将 pathogen 自身也置于独立目录中，需指定其路径 
"runtime bundle/pathogen/autoload/pathogen.vim
" 运行 pathogen
"execute pathogen#infect()

"git status
"git commit -m "add .vim plugins"
"cp ~/.vimrc .
"git add .vimrc
"git status
"git commit -m "add .vimrc file"
"git status
"git remote add origin https://github.com/zhchnchn/VimConfig.git
"git push -u origin master
"git push -u origin master：Push到远程仓库，同时设置跟踪分支，下次push的时候，直接输入git push即可，系统会自动用本地master分支跟踪远程master分支
"将.vim配置clone到别的机器的～/.vim目录下（如果没有.vim则新建一个）
"git clone git@github.com:zhchnchn/VimConfig.git ~/.vim

"pathogen.vim插件管理配置
execute pathogen#infect()
syntax on
syntax enable
if has('gui_running')
    "set background=light
    set background=dark
    "全屏
    set fu
    "如果底部有黑边
    defaults write org.vim.MacVim MMNativeFullScreen 0
else
    set background=light
    "set nofu
    "set background=dark
endif
"set background=dark
let g:solarized_termcolors=256
colorscheme solarized
filetype plugin indent on
"===================================插件配置=====================================================================
"=====================================ctrlp======================================================================

set runtimepath^=~/.vim/bundle/ctrlp.vim
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_working_path_mode = 'ra'
set wildignore+=*/tmp/*,*.so,*.swp,*.zip     " Linux/MacOSX
let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn)$'
let g:ctrlp_custom_ignore = {
    \ 'dir':  '\v[\/]\.(git|hg|svn)$',
    \ 'file': '\v\.(exe|so|dll)$',
    \ 'link': 'SOME_BAD_SYMBOLIC_LINKS',
    \ } 
let g:ctrlp_user_command = 'find %s -type f'        " MacOSX/Linux
let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files']
let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files . -co --exclude-standard', 'find %s -type f']
let g:ctrlp_user_command = ['.hg', 'hg --cwd %s locate -I .']
let g:ctrlp_user_command = {
    \ 'types': {
        \ 1: ['.git', 'cd %s && git ls-files'],
        \ 2: ['.hg', 'hg --cwd %s locate -I .'],
        \ },
    \ 'fallback': 'find %s -type f'
    \ }

"CtrlP会沿着vim打开的目录一直向上查找类似.git/.svn等这样的项目管理的目录，如果找到则将这个作为项目的根目录 vimrc中配置如下：
" "for file search ctrlp, 文件搜索
"" 打开ctrlp搜索
"let g:ctrlp_map = '<leader>ff'
"let g:ctrlp_cmd = 'CtrlP'
"" 相当于mru功能，show recently opened files
"map <leader>fp :CtrlPMRU<CR>
""set wildignore+=*/tmp/*,*.so,*.swp,*.zip     " MacOSX/Linux"
"let g:ctrlp_custom_ignore = {
"    \ 'dir':  '\v[\/]\.(git|hg|svn|rvm)$',
"    \ 'file': '\v\.(exe|so|dll|zip|tar|tar.gz)$',
"    \ }
""\ 'link': 'SOME_BAD_SYMBOLIC_LINKS',
"let g:ctrlp_working_path_mode=0
"let g:ctrlp_match_window_bottom=1
"let g:ctrlp_max_height=15
"let g:ctrlp_match_window_reversed=0
"let g:ctrlp_mruf_max=500
"let g:ctrlp_follow_symlinks=1
"===================================TagbarToggle=========================================================
nmap <F9> :TagbarToggle<CR>
" 启动时自动focus
let g:tagbar_autofocus = 1

" for ruby, delete if you do not need
let g:tagbar_type_ruby = {
    \ 'kinds' : [
        \ 'm:modules',
        \ 'c:classes',
        \ 'd:describes',
        \ 'C:contexts',
        \ 'f:methods',
        \ 'F:singleton methods'
    \ ]
\ }
"nmap <leader>tb :TagbarToggle<CR>  " \tb 打开tagbar窗口
"let g:tagbar_autofocus = 1
"=========================================NERDTree=======================================================
autocmd vimenter * NERDTree
let g:NERDTreeQuitOnOpen=0
" show hidden files in NERDTree
let NERDTreeShowHidden=1
" Toggle NERDTree
nmap <F8> :NERDTreeToggle<CR>
" expand to the path of the file in the current buffer
nmap <silent> <leader>y :NERDTreeFind<cr>

" map fuzzyfinder (CtrlP) plugin
" nmap <silent> <leader>t :CtrlP<cr>
nmap <silent> <leader>r :CtrlPBuffer<cr>
let g:ctrlp_map='<leader>t'
let g:ctrlp_dotfiles=1
let g:ctrlp_working_path_mode = 'ra'

" CtrlP ignore patterns
let g:ctrlp_custom_ignore = {
            \ 'dir': '\.git$\|node_modules$\|\.hg$\|\.svn$',
            \ 'file': '\.exe$\|\.so$'
            \ }

" search the nearest ancestor that contains .git, .hg, .svn
let g:ctrlp_working_path_mode = 2

"nmap <leader>nt :NERDTree<CR>
"let NERDTreeHighlightCursorline=1
"let NERDTreeIgnore=[ '\.pyc$', '\.pyo$', '\.obj$', '\.o$', '\.so$', '\.egg$', '^\.git$', '^\.svn$', '^\.hg$' ]
"let g:netrw_home='~/bak'
""close vim if the only window left open is a NERDTree
"autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | end
"========================================================================================================
"=========================================air-line=======================================================
""
":set guifont=*  调出字体设置
":set guifont    显示当前字体
"设置时，注意下划线代替空格，或者用\（转义字符）代替空格  =（等号）后面不能有空格
"
"let g:airline_detect_whitespace          = 0 "关闭空白符检测
"let g:airline#extensions#tabline#enabled = 1 "顶部tab栏显示
"let g:airline_theme                      = "bubblegum" "设定主题
""
""
"let g:Powerline_symbols = 'fancy'
set encoding=utf-8
"set fillchars+=stl:\ ,stlnc:\
"set laststatus=2
"set -g default-terminal "screen-256color"
set guifont=Meslo_LG_M_DZ_Regular_for_Powerline:h11
let g:airline_powerline_fonts = 1
"let g:Powerline_symbols="fancy"
"==================================================================================================
"=========================================Syntastic================================================
""
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

let g:syntastic_check_on_open = 1
let g:syntastic_cpp_include_dirs = ['/usr/include/']
let g:syntastic_cpp_remove_include_errors = 1
let g:syntastic_cpp_check_header = 1
let g:syntastic_cpp_compiler = 'clang++'
let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libstdc++'
"set error or warning signs
let g:syntastic_error_symbol = '✗'
let g:syntastic_warning_symbol = '⚠'
"whether to show balloons
let g:syntastic_enable_balloons = 1
"==================================================================================================
"=========================================gundo====================================================
let g:gundo_prefer_python3 = 1
nnoremap <F5> :GundoToggle<CR>
"let g:gundo_width = 60
"let g:gundo_preview_height = 40
"let g:gundo_right = 1
"==================================================================================================
"==========================================YCM========================================================
let g:ycm_confirm_extra_conf = 1
"let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_global_ycm_extra_conf = '/Users/BLUE/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_seed_identifiers_with_syntax = 1
set tags+=~/work/test/ctest/UPlayer_Refactoring_Tudou/tags
let g:ycm_confirm_extra_conf = 0
let g:ycm_server_keep_logfiles = 1
let g:ycm_server_log_level = 'debug'
nnoremap <leader>gl :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>gf :YcmCompleter GoToDefinition<CR>
nnoremap <leader>gg :YcmCompleter GoToDefinitionElseDeclaration<CR>
"注释和字符串中的文字也会被收入补全
let g:ycm_collect_identifiers_from_comments_and_strings = 1
" 输入第2个字符开始补全
let g:ycm_min_num_of_chars_for_completion=2
" 禁止缓存匹配项,每次都重新生成匹配项
let g:ycm_cache_omnifunc=0
" 开启语义补全
let g:ycm_seed_identifiers_with_syntax=1    
"在注释输入中也能补全
let g:ycm_complete_in_comments = 1
"在字符串输入中也能补全
let g:ycm_complete_in_strings = 1

let g:ycm_use_ultisnips_completer = 1
" 设置在下面几种格式的文件上屏蔽ycm
let g:ycm_filetype_blacklist = {
      \ 'tagbar' : 1,
      \ 'nerdtree' : 1,
      \}
"youcompleteme  默认tab  s-tab 和 ultisnips 冲突
let g:ycm_key_list_select_completion = ['<Down>']
let g:ycm_key_list_previous_completion = ['<Up>']
" 修改对C函数的补全快捷键，默认是CTRL + space，修改为ALT + ;
let g:ycm_key_invoke_completion = '<M-;>'

" YCM 补全菜单配色
" 菜单
"highlight Pmenu ctermfg=2 ctermbg=3 guifg=#005f87 guibg=#EEE8D5
" 选中项
"highlight PmenuSel ctermfg=2 ctermbg=3 guifg=#AFD700 guibg=#106900
" 补全功能在注释中同样有效
"let g:ycm_complete_in_comments=1
" 允许 vim 加载 .ycm_extra_conf.py 文件，不再提示
"let g:ycm_confirm_extra_conf=0
" 开启 YCM 标签补全引擎
"let g:ycm_collect_identifiers_from_tags_files=1
" 引入 C++ 标准库tags
"set tags+=/data/misc/software/misc./vim/stdcpp.tags
" YCM 集成 OmniCppComplete 补全引擎，设置其快捷键
"inoremap <leader>; <C-x><C-o>
" 补全内容不以分割子窗口形式出现，只显示补全列表
"set completeopt-=preview
" 从第一个键入字符就开始罗列匹配项
"let g:ycm_min_num_of_chars_for_completion=1
" 禁止缓存匹配项，每次都重新生成匹配项
"let g:ycm_cache_omnifunc=0
" 语法关键字补全         
"let g:ycm_seed_identifiers_with_syntax=1
"===================================================================================================
"=======================================ultisnips===================================================
" Track the engine.
"Plugin 'SirVer/ultisnips'

" Snippets are separated from the engine. Add this if you want them:
"Plugin 'honza/vim-snippets'

" Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
"let g:UltiSnipsExpandTrigger="<tab>"
"let g:UltiSnipsJumpForwardTrigger="<c-b>"
"let g:UltiSnipsJumpBackwardTrigger="<c-z>"
let g:UltiSnipsExpandTrigger="<c-j>"
let g:UltiSnipsJumpForwardTrigger="<c-j>"
let g:UltiSnipsJumpBackwardTrigger="<c-k>"


let g:UltiSnipsExpandTrigger = "<c-j>"
let g:UltiSnipsJumpForwardTrigger = "<c-j>"
let g:UltiSnipsJumpBackwardTrigger = "<c-k>"
" 定义存放代码片段的文件夹 .vim/additional_snippets下，使用自定义和默认的，将会的到全局，有冲突的会提示
let g:UltiSnipsSnippetDirectories=["additional_snippets", 'UltiSnips']

" If you want :UltiSnipsEdit to split your window.
let g:UltiSnipsEditSplit="vertical"
"===================================================================================================
"========================================EasyAlign==================================================
" Start interactive EasyAlign in visual mode (e.g. vipga)
xmap ga <Plug>(EasyAlign)

" Start interactive EasyAlign for a motion/text object (e.g. gaip)
nmap ga <Plug>(EasyAlign)
"===================================================================================================
"=========================================AG========================================================
let g:ag_prg="<custom-ag-path-goes-here> --vimgrep"
let g:ag_working_path_mode="r"
"===================================================================================================
"=========================================BufferLine================================================
"" 开启tabline
"let g:airline#extensions#tabline#enabled = 1
"" tabline中当前buffer两端的分隔符
"let g:airline#extensions#tabline#left_sep = ' '
"" tabline为激活的buffer的两端字符
"let g:airline#extensions#tabline#left_alt_sep = '|'
"" tabline中buffer显示编号
"let g:airline#extensions#tabline#buffer_nr_show = 1
"let g:airline#extensions#buffline#enabled = 1
"let g:airline#extensions#bufferline#overwrite_variables = 1

" enable tabline
"let g:airline#extensions#tabline#enabled = 1
" set left separator
"let g:airline#extensions#tabline#left_sep = ' '
" set left separator which are not editting
"let g:airline#extensions#tabline#left_alt_sep = '|'
" show buffer number
"let g:airline#extensions#tabline#buffer_nr_show = 1
"===================================================================================================
"============================================vimproc=======================================================
"sudo git submodule add -f  https://github.com/Shougo/vimproc.vim.git bundle/vimproc.vim
"===================================================================================================
"==============================================vimshell=====================================================
"sudo git submodule add -f  https://github.com/Shougo/vimshell.vim.git bundle/vimshell.vim
"let g:vimshell_user_prompt = 'fnamemodify(getcwd(), ":~")'
let g:vimshell_user_prompt = 'fnamemodify(getcwd(), ":~")'
"used VimShellPop open windows
	"let g:vimshell_right_prompt = 'vcs#info("(%s)-[%b]", "(%s)-[%b|%a]")'
	
	if has('win32') || has('win64')
	  " Display user name on Windows.
	  let g:vimshell_prompt = $USERNAME."% "
	else
	  " Display user name on Linux.
	  let g:vimshell_prompt = $USER."% "
	endif
let g:vimshell_environment_term = 'zsh'
"===================================================================================================
"==============================================vim-indent-guides=============================================
"sudo git submodule add https://github.com/nathanaelkane/vim-indent-guides.git bundle/vim-indentt-guides.vim
" 随 vim 自启动
let g:indent_guides_enable_on_vim_startup=1
" 从第二层开始可视化显示缩进
let g:indent_guides_start_level=2
" 色块宽度
let g:indent_guides_guide_size=1
" 快捷键 i 开/关缩进可视化
:nmap <silent> <Leader>i <Plug>IndentGuidesToggle

if has('gui_running')
"
"autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd  guibg=red   ctermbg=3
"autocmd VimEnter,Colorscheme * :hi IndentGuidesEven guibg=green ctermbg=4

"hi IndentGuidesOdd  guibg=red   ctermbg=3
"hi IndentGuidesEven guibg=green ctermbg=4

"hi IndentGuidesOdd  ctermbg=black
"hi IndentGuidesEven ctermbg=darkgrey
else
"autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd  guibg=red   ctermbg=3
"autocmd VimEnter,Colorscheme * :hi IndentGuidesEven guibg=green ctermbg=4

"hi IndentGuidesOdd  guibg=red   ctermbg=3
"hi IndentGuidesEven guibg=green ctermbg=4

"hi IndentGuidesOdd  ctermbg=white
"hi IndentGuidesEven ctermbg=lightgrey
endif


"autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd  guibg=red   ctermbg=3
"autocmd VimEnter,Colorscheme * :hi IndentGuidesEven guibg=green ctermbg=4
"===================================================================================================
"==============================================a.vim=====================================================
"sudo git submodule add https://github.com/vim-scripts/a.vim.git bundle/a.vim
" *.cpp 和 *.h 间切换
nmap <Leader>ch :A<CR>
" 子窗口中显示 *.cpp 或 *.h
nmap <Leader>sch :AS<CR>
这样，键入 ;ch 就能在实现文件和接口文件间切换，键入 ;sch 子窗口中将显示实现文件/接口文件。
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================
"===================================================================================================

set nocompatible
set number
" 总是显示状态栏
set laststatus=2
" 显示光标当前位置
set ruler
" 开启行号显示
set number
" 高亮显示当前行/列
set cursorline
set cursorcolumn
" 高亮显示搜索结果
set hlsearch
"使用鼠标
set mouse=a
"去掉输入错误的提示声音
set noeb
"ctags -R --c++-kinds=+p --fields=+iaS --extra=+q src
map <c-F12> :!CTags -R --c++-kinds=+p --fields=+iaSl --extra=+q .<CR><CR>
map <C-F12> :!ctags -R --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+liaS --extra=+q --language-force=c++ ./


"中文帮助和中文菜单
"if version >= 603
set helplang=cn
"set encoding=utf-8
"endif
"========================================================================================================
" The default for 'backspace' is very confusing to new users, so change it to a
" more sensible value.  Add "set backspace&" to your ~/.vimrc to reset it.
set backspace+=indent,eol,start

" Disable localized menus for now since only some items are translated (e.g.
" the entire MacVim menu is set up in a nib file which currently only is
" translated to English).
set langmenu=none

"========================================================================================================
":buffers	列示缓冲区状态
":buffer	编辑指定缓冲区
":ball	编辑所有缓冲区
":bnext	到下一缓冲区
":bprevious	到前一缓冲区
":blast	到最后一个缓冲区
":bfirst	到第一个缓冲区
":badd	增加缓冲区
":bdelete	删除缓冲区
":bunload	卸载缓冲区
":buffers	列示缓冲区状态
":buffer	编辑指定缓冲区
":ball	编辑所有缓冲区
":bnext	到下一缓冲区
":bprevious	到前一缓冲区
":blast	到最后一个缓冲区
":bfirst	到第一个缓冲区
":badd	增加缓冲区
":bdelete	删除缓冲区
":bunload	卸载缓冲区
":bwipe		彻底删除缓冲区

"========================================================================================================
" 定义快捷键的前缀，即<Leader>
"let mapleader=";"
" 定义快捷键到行首和行尾
"nmap LB 0
"nmap LE $
" 设置快捷键将选中文本块复制至系统剪贴板
"vnoremap <Leader>y "+y
" 设置快捷键将系统剪贴板内容粘贴至 vim
"nmap <Leader>p "+p
" 定义快捷键关闭当前分割窗口
"nmap <Leader>q :q<CR>
" 定义快捷键保存当前窗口内容
"nmap <Leader>w :w<CR>
" 定义快捷键保存所有窗口内容并退出 vim
"nmap <Leader>WQ :wa<CR>:q<CR>
" 不做任何保存，直接退出 vim
"nmap <Leader>Q :qa!<CR>
" 依次遍历子窗口
"nnoremap nw <C-W><C-W>
" 跳转至右方的窗口
"nnoremap <Leader>lw <C-W>l
" 跳转至左方的窗口
"nnoremap <Leader>hw <C-W>h
" 跳转至上方的子窗口
"nnoremap <Leader>kw <C-W>k
" 跳转至下方的子窗口
"nnoremap <Leader>jw <C-W>j
" 定义快捷键在结对符之间跳转
"nmap <Leader>M %


" 开启实时搜索功能
"set incsearch
" 搜索时大小写不敏感
"set ignorecase
" 关闭兼容模式
"set nocompatible
" vim 自身命令行模式智能补全
"set wildmenu
" 禁止光标闪烁
"set gcr=a:block-blinkon0
" 禁止显示滚动条
"set guioptions-=l
"set guioptions-=L
"set guioptions-=r
"set guioptions-=R
" 禁止显示菜单和工具条
"set guioptions-=m
"set guioptions-=T
" 总是显示状态栏
"set laststatus=2
" 显示光标当前位置
"set ruler
" 开启行号显示
"set number
" 高亮显示当前行/列
"set cursorline
"set cursorcolumn
" 高亮显示搜索结果
"set hlsearch
" 禁止折行
"set nowrap
" 设置状态栏主题风格
"let g:Powerline_colorscheme='solarized256'
" 设置 gvim 显示字体
"set guifont=YaHei\ Consolas\ Hybrid\ 11.5


" 开启语法高亮功能
"syntax enable
" 允许用指定语法高亮配色方案替换默认方案
"syntax on


"在 vim 中有两类缩进表示法，一类是用 1 个制表符（'\t'），一类是用多个空格（' "'）。两者并无本质区别，只是源码文件存储的字符不同而已，但，缩进可视化插件对两类缩进显示方式不同，前者只能显示为粗块，后者可显示为细条，就我的审美观而言，选后者。增加如下配置信息：

" 自适应不同语言的智能缩进
"filetype indent on
" 将制表符扩展为空格
"set expandtab
" 设置编辑时制表符占用空格数
"set tabstop=4
" 设置格式化时制表符占用空格数
"set shiftwidth=4
" 让 vim 把连续数量的空格视为一个制表符
"set softtabstop=4
"其中，注意下 expandtab、tabstop 与 shiftwidth、softtabstop、retab：

"expandtab，把制表符转换为多个空格，具体空格数量参考 tabstop 和 shiftwidth 变量；
"tabstop 与 shiftwidth 是有区别的。tabstop 指定我们在插入模式下输入一个制表符占据的空格数量，linux 内核编码规范建议是 8，看个人需要；shiftwidth 指定在进行缩进格式化源码时制表符占据的空格数。所谓缩进格式化，指的是通过 vim 命令由 vim 自动对源码进行缩进处理，比如其他人的代码不满足你的缩进要求，你就可以对其进行缩进格式化。缩进格式化，需要先选中指定行，要么键入 = 让 vim 对该行进行智能缩进格式化，要么按需键入多次 < 或 > 手工缩进格式化；
"softtabstop，如何处理连续多个空格。因为 expandtab 已经把制表符转换为空格，当你要删除制表符时你得连续删除多个空格，该设置就是告诉 vim 把连续数量的空格视为一个制表符，即，只删一个字符即可。通常应将这tabstop、shiftwidth、softtabstop 三个变量设置为相同值；
"另外，你总会阅读其他人的代码吧，他们对制表符定义规则与你不同，这时你可以手工执行 vim 的 retab 命令，让 vim 按上述规则重新处理制表符与空格关系。

"操作：za，打开或关闭当前折叠；zM，关闭所有折叠；zR，打开所有折叠。
"" 基于缩进或语法进行代码折叠
""set foldmethod=indent
"set foldmethod=syntax
"" 启动 vim 时关闭折叠代码
"set nofoldenable



