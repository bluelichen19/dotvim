"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Maintainer: 
"       bluelichen
"       https://github.com/bluelichen19
"
" Version: 
"       1.0 - 29/05/12 15:43:36
"
" Blog_post: 
"       http://amix.dk/blog/post/19691#The-ultimate-Vim-configuration-on-Github
"
" Awesome_version:
"       Get this config, nice color schemes and lots of plugins!
"
"       Install the awesome version from:
"
"           https://github.com/amix/vimrc
"
" Syntax_highlighted:
"       http://amix.dk/vim/vimrc.html
"
" Raw_version: 
"       http://amix.dk/vim/vimrc.txt
"
" Sections:
"    -> General
"    -> VIM user interface
"    -> Colors and Fonts
"    -> Files and backups
"    -> Text, tab and indent related
"    -> Visual mode related
"    -> Moving around, tabs and buffers
"    -> Status line
"    -> Editing mappings
"    -> vimgrep searching and cope displaying
"    -> Spell checking
"    -> Misc
"    -> Helper functions
"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Sets how many lines of history VIM has to remember
set history=700

" Enable filetype plugins
filetype plugin on
filetype indent on

" Set to auto read when a file is changed from the outside
set autoread

" With a map leader it's possible to do extra key combinations
" like <leader>w saves the current file
let mapleader = ","
let g:mapleader = ","

" Fast saving
nmap <leader>w :w!<cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Set 7 lines to the cursor - when moving vertically using j/k
set so=7
" Turn on the WiLd menu
set wildmenu

" Ignore compiled files
set wildignore=*.o,*~,*.pyc,*.svn-base

"Always show current position
set ruler
" Height of the command bar
"set cmdheight=2

" A buffer becomes hidden when it is abandoned
set hid

" Configure backspace so it acts as it should act
"set backspace=eol,start,indent
"set whichwrap+=<,>,h,l

" Ignore case when searching
set ignorecase

" When searching try to be smart about cases 
set smartcase

" Highlight search results
set hlsearch

" Makes search act like search in modern browsers
set incsearch

" Don't redraw while executing macros (good performance config)
set lazyredraw

" For regular expressions turn magic on
set magic

" Show matching brackets when text indicator is over them
set showmatch
" How many tenths of a second to blink when matching brackets
set mat=2

" No annoying sound on errors
set noerrorbells
set novisualbell
set t_vb=
set tm=500
"防止特殊符号无法正常显示  
set ambiwidth=double  
"设置默认编码  
set encoding=utf-8  
set langmenu=zh_CN.UTF-8  
"提示信息乱码解决"  
language message zh_CN.UTF-8  
"菜单乱码解决"  
source $VIMRUNTIME/delmenu.vim  
source $VIMRUNTIME/menu.vim  
""set encoding=cp936  
"设置文件编码  
""set fileencodings=utf-8,cp936,chinese,latin-1,ucs-bom,gb18030,big5,euc-jp,euc-kr,latin1,gbk,gb2321  
set fileencodings=ucs-bom,chinese,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1  

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Enable syntax highlighting
syntax enable

if has('gui_running')
	set fuoptions=maxvert,maxhorz
    au GUIEnter * set fullscreen

    ""set background=light
    set background=dark
    colorscheme solarized
    "全屏 "如果底部有黑边
    "{
        "set background=dark
    	"colorscheme solarized
    	"let shellcmd = 'defaults write org.vim.MacVim MMNativeFullScreen 0 '
    	"let output = system(shellcmd)
    	"set fu
    "}
    set guitablabel=%M\ %t
else
    set background=light
    colorscheme molokai
    "set nofu
    "set background=dark
endif
"set background=dark
let g:solarized_termcolors=256
"colorscheme solarized
"colorscheme molokai
"colorscheme phd

"colorscheme desert
"set background=dark

" Set extra options when running in GUI mode
"if has("gui_running")
"    set guioptions-=T
"    set guioptions+=e
"    set t_Co=256
"    set guitablabel=%M\ %t
"endif

" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8

" Use Unix as the standard file type
set ffs=unix,dos,mac

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Files, backups and undo
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Turn backup off, since most stuff is in SVN, git et.c anyway...
set nobackup
"set nowb
set noswapfile

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Text, tab and indent related
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Use spaces instead of tabs
set expandtab

" Be smart when using tabs ;)
set smarttab

" 1 tab == 4 spaces
set shiftwidth=4
set tabstop=4

""""""""""""""""""""""""""""""
" => Status line
""""""""""""""""""""""""""""""
" Always show the status line
set laststatus=2

" Format the status line
set statusline=\ %{HasPaste()}%F%m%r%h\ %w\ \ CWD:\ %r%{getcwd()}%h\ \ \ Line:\ %l

" status line {
"set laststatus=2
"set statusline=\ %{HasPaste()}%<%-15.25(%f%)%m%r%h\ %w\ \ 
"set statusline+=\ \ \ [%{&ff}/%Y] 
"set statusline+=\ \ \ %<%20.30(%{hostname()}:%{CurDir()}%)\ 
"set statusline+=%=%-10.(%l,%c%V%)\ %p%%/%L

function! CurDir()
    let curdir = substitute(getcwd(), $HOME, "~", "")
    return curdir
endfunction

function! HasPaste()
    if &paste
        return '[PASTE]'
    else
        return ''
    endif
endfunction

"}

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
"set langmenu=zh_CN.UTF-8
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
filetype plugin indent on
"===================================插件配置=====================================================================
"=====================================ctrlp======================================================================

let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'
"let g:ctrlp_working_path_mode = 'ra'
let g:ctrlp_working_path_mode = 0
map <Leader>p :CtrlP<cr>
map <c-m> :CtrlPMixed<cr>
map <c-b> :CtrlPBuffer<cr>
let g:ctrlp_open_new_file = 'r'
set wildignore+=*/.git/*,*/.hg/*,*/.svn/*,*/svn-base,*/so,*.swp,*/zip       " Linux/MacOSX
let g:ctrlp_custom_ignore = {
    \ 'dir':  '\v[\/]\.(git|hg|svn|rvm)$',
    \ 'file': '\v\.(exe|so|dll|zip|tar|tar.gz|pyc)$',
    \ }
let g:ctrlp_match_window_bottom=1
let g:ctrlp_max_height=15
let g:ctrlp_match_window_reversed=0
let g:ctrlp_mruf_max=500
let g:ctrlp_follow_symlinks=1
let g:ctrlp_match_window_reversed=0
let g:ctrlp_mruf_max=500
let g:ctrlp_max_height = 20
let g:ctrlp_custom_ignore = 'node_modules\|^\.DS_Store\|^\.git\|^\.coffee'

let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn)$'
let g:ctrlp_user_command = 'find %s -type f'        " MacOSX/Linux
"let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files']
"let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files . -co --exclude-standard', 'find %s -type f']
"let g:ctrlp_user_command = ['.hg', 'hg --cwd %s locate -I .']
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
""\ 'link': 'SOME_BAD_SYMBOLIC_LINKS',


"名词对照（译注）

 " buffer:缓冲区                    mapping:按键绑定
 "    mru:最近最多使用               prompt:提示符面板
 "    tag:标签                          tab:页签
 "    tab:制表符

"===============================================================================
"内容                                                            *ctrlp-content*

 "   1. 介绍.............................................|ctrlp-intro|
 "   2. 选项.............................................|ctrlp-options|
 "   3. 命令.............................................|ctrlp-commands|
 "   4. 按键绑定.........................................|ctrlp-mappings|
 "   5. 输入格式.........................................|ctrlp-input-formats|
 "   6. 扩展.............................................|ctrlp-extensions|

"===============================================================================
"介绍                                                              *ctrlp-intro*

"带有直观接口的全路径模糊文件, 缓冲区, 最近最多使用, 标签, ... 检索。
"使用纯净的Vimscript编写，可以运行在MacVim，gVim和版本号7.0以上的Vim中。
"全面支持Vim的正则表达式 |regexp| 作为搜索模式，内建最近最多使用文件监测，
"项目根目录定位和更多特性。

"开启可选的扩展（标记，目录，rtscripts...），参考 |ctrlp-extensions| 。

"===============================================================================
"OPTIONS                                                         *ctrlp-options*

"总览:~

"  |loaded_ctrlp|................禁用插件。
"  |ctrlp_map|...................默认按键绑定。
"  |ctrlp_cmd|...................默认按键绑定调用的命令。
"  |ctrlp_by_filename|...........是否默认开启文件名模式。
"  |ctrlp_regexp|................是否默认开启正则表达式模式。
"  |ctrlp_match_window|..........匹配窗口的显示位置。
"  |ctrlp_switch_buffer|.........如果文件已在缓冲区中打开，跳转到该打开的缓冲区。
"  |ctrlp_reuse_window|..........重用特殊窗口（帮助、快速修复 |quickfix| ，等等）。
"  |ctrlp_tabpage_position|......新标签页出现的位置。
"  |ctrlp_working_path_mode|.....如何设置CtrlP的本地工作目录。
"  |ctrlp_root_markers|..........额外的，高优先级的根目录标识。
"  |ctrlp_use_caching|...........针对每个会话，设置是否开启缓存的。
"  |ctrlp_clear_cache_on_exit|...退出Vim后是否保留缓存。
"  |ctrlp_cache_dir|.............缓存目录的位置。
"  |ctrlp_show_hidden|...........是否显示隐藏文件和隐藏文件夹。
"  |ctrlp_custom_ignore|.........使用 |globpath()| 时自定义忽略的文件或目录。
"  |ctrlp_max_files|.............扫描文件的最大数目。
"  |ctrlp_max_depth|.............扫描目录的最大层数。
"  |ctrlp_user_command|..........使用外部的扫描工具。
"  |ctrlp_max_history|...........历史提示符面板中保留的最大条目数。
"  |ctrlp_open_new_file|.........由<c-y>创建的文件的打开方式。
"  |ctrlp_open_multiple_files|...由<c-z>选择的文件的打开方式。
"  |ctrlp_arg_map|...............是否拦截<c-y> 和 <c-o> 命令。
"  |ctrlp_follow_symlinks|.......是否跟随链接。
"  |ctrlp_lazy_update|...........停止输入时才更新。
"  |ctrlp_default_input|.........为提示符面板提供一个种子。
"  |ctrlp_abbrev|................输入缩写。
"  |ctrlp_key_loop|..............为多字节输入开启输入事件循环。
"  |ctrlp_prompt_mappings|.......改变提示符面板内部的按键绑定。

"  最近最多使用模式:
"  |ctrlp_mruf_max|..............记录的最近最多使用的最大数据。
"  |ctrlp_mruf_exclude|..........需要被排除的文件。
"  |ctrlp_mruf_include|..........需要被记录的文件。
"  |ctrlp_mruf_relative|.........只显示在工作目录内的最近最多使用。
"  |ctrlp_tilde_homedir|.........保存 home 目录中的 MRU 的目录路径为波浪扩展的形式 ~/。
"  |ctrlp_mruf_default_order|....禁用排序。
"  |ctrlp_mruf_case_sensitive|...最近最多使用文件是否大小写敏感。
"  |ctrlp_mruf_save_on_update|...只要有一个新的条目添加，就保存到磁盘。
"  |ctrlp_mruf_exclude_nomod|....从 MRU 中排除不可编辑的缓冲区。

"  缓冲区标签模式: (开启此模式，参考 |ctrlp-extensions| )
"  |g:ctrlp_buftag_ctags_bin|....兼容的ctags二进制程序的位置。
"  |g:ctrlp_buftag_systemenc|....ctags命令的编码。
"  |g:ctrlp_buftag_types|........添加新的文件类型和设置命令行参数。

"  高级选项:
"  |ctrlp_open_func|.............使用自定义的打开文件的函数。
"  |ctrlp_status_func|...........改变CtrlP的两个状态栏
"  |ctrlp_buffer_func|...........在CtrlP的缓冲区内调用自定义的函数。
"  |ctrlp_match_func|............替换内建的匹配算法。

"-------------------------------------------------------------------------------
"详细描述和默认值:~

"                                                                *'g:ctrlp_map'*
"使用该选项来改变普通模式 |Normal| 下调用CtrlP的按键绑定: >
"  let g:ctrlp_map = '<c-p>'
"<

 "                                                               *'g:ctrlp_cmd'*

"设置当按下上面的按键绑定时，使用的默认打开命令: >
"  let g:ctrlp_cmd = 'CtrlP'
"<
"
"                                                             *'g:loaded_ctrlp'*
"使用该选项完全禁用插件: >
"  let g:loaded_ctrlp = 1
"<

 "                                                       *'g:ctrlp_by_filename'*
"修改该选项为1，设置默认为按文件名搜索（否则为全路径）: >
"  let g:ctrlp_by_filename = 0
"<
"在提示符面板内可以使用 <c-d> 来切换。

"                                                            *'g:ctrlp_regexp'*
"修改该选项为1，设置默认为使用正则表达式匹配。: >
"  let g:ctrlp_regexp = 0
"<
"在提示符面板内可以使用 <c-r> 来切换。

"                                                      *'g:ctrlp_match_window'*
"改变匹配窗口的位置，结果的排列顺序，最小和最大高度: >
"  let g:ctrlp_match_window = ''
"<
"例子: >
"  let g:ctrlp_match_window = 'bottom,order:btt,min:1,max:10,results:10'
"<
"位置: (默认:底部)
"  top - 在屏幕顶部显示匹配窗口。
"  bottom - 在屏幕底部显示匹配窗口。

"结果的排列顺序: (默认: btt)
"  order:ttb - 从顶部到底部。
"  order:btt - 从底部到顶部。

"最小和最大高度:
"  min:{n} - 最少显示 {n} 行 (默认: 1).
"  max:{n} - 最多显示 {n} 行 (默认: 10).

"结果集的最大数目:
"  results:{n} - 列出最多 {n} 条结果 (默认: 和最大高度同步).

"注意: 当一个设置项没有被设置时，将会使用默认值。

"                                                      *'g:ctrlp_switch_buffer'*
"当尝试打开一个文件时，如果它已经在某个窗口被打开，CtrlP会尝试跳到那个窗口，而
"不是新打开一个实例。: >
"  let g:ctrlp_switch_buffer = 'Et'
"<
"  e - 当 <cr> 被按下时跳转，但是只跳转到当前页签内的窗口内。
"  t - 当 <c-t> 被按下时跳转, 但是只跳转到其它标签的窗口内。
"  v - 类似 "e", 但是当 <c-v> 被按下时跳转。
"  h - 类似 "e", 但是当 <c-x> 被按下时跳转。
"  E, T, V, H - 行为类似 "e", "t", "v", and "h", 但是跳转到任何地方的窗口中。
"  0 或者 <empty> - 禁用这项功能。

"                                                       *'g:ctrlp_reuse_window'*
"当使用 <cr> 打开新文件时，CtrlP避免在插件，帮助，快速修复创建的窗口中打开该文
"件。使用该选项来设置一些例外: >
"  let g:ctrlp_reuse_window = 'netrw'
"<
"接受的值可以为特殊缓冲区的名字的一部分，文件类型或者缓冲区类型使用正则表达式来
"指定匹配模式。
"例子: >
"  let g:ctrlp_reuse_window = 'netrw\|help\|quickfix'
"<

"                                                  *'g:ctrlp_tabpage_position'*
"新打开页签的位置: >
"  let g:ctrlp_tabpage_position = 'ac'
"<
"  a - 后面。
"  b - 前面。
"  c - 当前页签。
"  l - 最后一个页签。
"  f - 第一个页签。

"                                                  *'g:ctrlp_working_path_mode'*
"当启动时，CtrlP依据这个变量来设置它的工作目录: >
"  let g:ctrlp_working_path_mode = 'ra'
"<
"  c - 当前文件所在的目录。
"  a - 当前文件所在的目录，除非这个目录为当前工作目录的子目录
"  r - 包含下列文件或者目录的最近的祖先目录:
"      .git .hg .svn .bzr _darcs
"  w - 用来修饰r：使用当前工作目录而不是当前文件所在目录进行查找
"  0 或者 <empty> - 禁用这项功能。

"注意 #1: 如果 "a" 或者 "c" 和 "r"一起被包含，当无法找到根目录时使用 "a" 或者 
""c" 的行为（作为备选）。

"注意 #2: 你可以在每个缓冲区内使用 |b:var| 来设置该选项。

"                                                       *'g:ctrlp_root_markers'*
"使用该选项来设置自定义的根目录标记作为对默认标记(.hg, .svn, .bzr, and _darcs)
"的补充。自定义的标记具有优先权: >
"  let g:ctrlp_root_markers = ['']
"<
"注意: 你可以在每个缓冲区内使用 |b:var| 来设置该选项。

"                                                        *'g:ctrlp_use_caching'*
"启用/禁用每个会话的缓存: >
"  let g:ctrlp_use_caching = 1
"<
"  0 - 禁用缓存。
"  1 - 启用缓存。
"  n - 当大于1时，禁用缓存，使用该数值作为重新启用缓存的限制条件。

"注意: 当在CtrlP中时你可以使用 <F5> 来快速的清除缓存。

 "                                               *'g:ctrlp_clear_cache_on_exit'*
"设置该选项为0通过退出Vim时不删除缓存文件来启用跨会话的缓存: >
"  let g:ctrlp_clear_cache_on_exit = 1
"<

"                                                          *'g:ctrlp_cache_dir'*
"设置存储缓存文件的目录: >
"  let g:ctrlp_cache_dir = $HOME.'/.cache/ctrlp'
"<

"                                                        *'g:ctrlp_show_hidden'*
"如果你想CtrlP扫描隐藏文件和目录，设置该选项为1: >
"  let g:ctrlp_show_hidden = 0
"<
"注意: 当命令使用 |g:ctrlp_user_command| 定义时该选项无效。

"                                                           *'ctrlp-wildignore'*
"你可以使用Vim的 |'wildignore'| 来从结果集中排序文件或目录。
"例子: >
"  " 排除版本控制文件
"  set wildignore+=*/.git/*,*/.hg/*,*/.svn/*        " Linux/MacOSX
"  set wildignore+=*\\.git\\*,*\\.hg\\*,*\\.svn\\*  " Windows ('noshellslash')
"<
"注意 #1: 每个目录设置前的字符 `*/` 是必须的。

"注意 #2: |wildignore| 影响 |expand()| ， |globpath()| 和 |glob()| 的结果，这些函数被很
"多插件用来在系统中执行查找。（例如和版本控制系统有关的插件在查找.git/、.hg/等，
"一些其他插件用来在Windows上查找外部的*.exe工具），所以要修改 |wildignore| 时请先
"考虑清楚。

"                                                      *'g:ctrlp_custom_ignore'*
"作为对 |'wildignore'| 的补充，用来设置你只是想在CtrlP中隐藏的文件和目录。使用正
"则表达式来指定匹配模式: >
"  let g:ctrlp_custom_ignore = ''
"<
"例子: >
"  let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn)$'
"  let g:ctrlp_custom_ignore = {
"    \ 'dir':  '\v[\/]\.(git|hg|svn)$',
"    \ 'file': '\v\.(exe|so|dll)$',
"    \ 'link': 'SOME_BAD_SYMBOLIC_LINKS',
"    \ }
"  let g:ctrlp_custom_ignore = {
"    \ 'file': '\v(\.cpp|\.h|\.hh|\.cxx)@<!$'
"    \ }
"  let g:ctrlp_custom_ignore = {
"    \ 'func': 'some#custom#match_function'
"    \ }
"<
"注意 #1: 默认情况下， |wildignore| 和 |g:ctrlp_custom_ignore| 只在 |globpath()| 被用
"来扫描文件的情况下使用，这样这些选项在那些使用 |g:ctrlp_user_command| 定义的命
"令中不会生效。 

"注意 #2: 当改变选项的变量类型时，记得先 |:unlet| ，或者重启Vim来避免这个错误：
""E706: Variable type mismatch" 。

"注意 #3: 当使用函数来忽略类型时，你必须提供CtrlP可以调用的函数的全名。建议使用
"自动加载的函数。函数必须接受两个参数，要匹配的条目和接受的类型，类型可以是目
"录、文件和链接。如果条目被忽略，函数需要返回1，反之，返回0。

"                                                          *'g:ctrlp_max_files'*
"扫描文件的最大数量，设置为0时不进行限制: >
"  let g:ctrlp_max_files = 10000
"<
"注意: 当命令使用 |g:ctrlp_user_command| 定义时该选项无效。

"                                                          *'g:ctrlp_max_depth'*
"目录树递归的最大层数: >
"  let g:ctrlp_max_depth = 40
"<
"注意: 当命令使用 |g:ctrlp_user_command| 定义时该选项无效。

"                                                      *'g:ctrlp_user_command'*
"指定用来代替Vim的 |globpath()| 的外部工具来列出文件，使用 %s 代表目标目录: >
"  let g:ctrlp_user_command = ''
"<
"例子: >
"  let g:ctrlp_user_command = 'find %s -type f'       " MacOSX/Linux
"  let g:ctrlp_user_command = 'dir %s /-n /b /s /a-d' " Windows
"<
"你也可以使用 'grep', 'findstr' 或者其它东西来过滤结果集。
"例子: >
"  let g:ctrlp_user_command =
"    \ 'find %s -type f | grep -v -P "\.jpg$|/tmp/"'          " MacOSX/Linux
"  let g:ctrlp_user_command =
"    \ 'dir %s /-n /b /s /a-d | findstr /v /l ".jpg \\tmp\\"' " Windows
"<
"在扫描一个大型项目时，在仓库目录中使用版本控制系统的列出命令会加快扫描速度: >
"  let g:ctrlp_user_command = [root_marker, listing_command, fallback_command]
"  let g:ctrlp_user_command = {
"    \ 'types': {
"      \ 1: [root_marker_1, listing_command_1],
"      \ n: [root_marker_n, listing_command_n],
"     \ },
"    \ 'fallback': fallback_command,
"    \ 'ignore': 0 or 1
"    \ }
"<
"一些例子: >
"  " 单个版本控制系统，列出命令不会列出没有被追踪的文件:
"  let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files']
"  let g:ctrlp_user_command = ['.hg', 'hg --cwd %s locate -I .']

"  " 多个版本控制系统:
"  let g:ctrlp_user_command = {
"    \ 'types': {
"      \ 1: ['.git', 'cd %s && git ls-files'],
"      \ 2: ['.hg', 'hg --cwd %s locate -I .'],
"      \ },
"    \ 'fallback': 'find %s -type f'
"    \ }

"  " 单个版本控制系统，列出命令列出没有被追踪的文件（较慢）:
"  let g:ctrlp_user_command =
"    \ ['.git', 'cd %s && git ls-files . -co --exclude-standard']

"  let g:ctrlp_user_command =
"    \ ['.hg', 'hg --cwd %s status -numac -I . $(hg root)'] " MacOSX/Linux

"  let g:ctrlp_user_command = ['.hg', 'for /f "tokens=1" %%a in (''hg root'') '
"    \ . 'do hg --cwd %s status -numac -I . %%a']           " Windows
"<
"注意 #1: 在 |Dictionary| 格式, 'fallback' 和 'ignore' 是可选的，在 |List| 格式，
"备选命令是可选的。

"注意 #2: 如果备选命令是空的或者属性 'fallback' 没有定义，当扫描仓库之外目录时，
"|globpath()| 会被使用。

"注意 #3: 除非使用了 |Dictionary| 格式并且 'ignore' 被定义并且设置为1，当这些自
"定义的命令被使用时 |wildignore| 和 |g:ctrlp_custom_ignore| 选项不会生效。没有出现
"时，'ignore' 被默认设置为0来保留使用外部命令的性能优势。

"注意 #4: 当改变了选项的变量类型时，记得先 |:unlet| ，或者重启Vim来避免这个错误：
""E706: Variable type mismatch" 。

"注意 #5: 你可以在每个缓冲区内使用 |b:var| 来设置该选项。

"                                                        *'g:ctrlp_max_history'*
"你希望CtrlP记录的用户输入历史的最大数目。默认值是Vim的全局选项 |'history'| : >
"  let g:ctrlp_max_history = &history
"<
"设置为0来禁用提示符面板的历史。使用 <c-n> 和 <c-p> 来浏览历史。

"                                                     *'g:ctrlp_open_new_file'*
"使用该选项指定当使用 <c-y> 打开新建的文件时，文件的打开方式: >
"  let g:ctrlp_open_new_file = 'v'
"<
"  t - 在新页签中。
"  h - 在新的水平分割窗口。
"  v - 在新的竖直分割窗口。
"  r - 在当前窗口。

"                                                *'g:ctrlp_open_multiple_files'*
"如果非0， 会启用使用 <c-z> 和 <c-o> 打开多个文件: >
"  let g:ctrlp_open_multiple_files = 'v'
"<
"例子: >
"  let g:ctrlp_open_multiple_files = '2vjr'
"<
"对于数字:
"  - 如果指定，会被用来作为打开文件时创建的窗口或者页签的最大数量（剩余的会在隐
"    藏的缓冲区中打开）。
"  - 如果没有指定，<c-o> 会打开所有文件，每个在一个新的窗口或者页签中。

"对于字母:
"  t - 每个文件在一个新页签中。
"  h - 每个文件在一个新的水平分割窗口中。
"  v - 每个文件在一个新的竖直分割窗口中。
"  i - 所有的文件在隐藏的缓冲区中。
"  j - 打开以后，跳转到第一个打开的页签或者窗口。
"  r - 在当前窗口打开第一个文件，其他文件根据同时出现的"h"，"v"和"t"中的一个，
"      在新的分割窗口或者页签中打开。

"                                                            *'g:ctrlp_arg_map'*
"当设置为1时， <c-o> 和 <c-y> 会接收一个额外的键值作为参数，来覆盖默认行为: >
"  let g:ctrlp_arg_map = 0
"<
"按下 <c-o> 或者 <c-y> 会提示一次按键。按键可以是:
"  t - 在新标签页中打开。
"  h - 每个文件在一个新的水平分割窗口中。
"  v - 每个文件在一个新的竖直分割窗口中。
"  i - 所有的文件在隐藏的缓冲区中（只有 <c-o> 生效）。
"  c - 清楚标记的文件（只有 <c-o> 生效）。
"  r - 在当前窗口中打开（只有 <c-y> 生效）。
"  <esc>, <c-c>, <c-u> - 取消并且回到提示符面板。
"  <cr> - 使用 |g:ctrlp_open_new_file| 和 |g:ctrlp_open_multiple_files| 指定的默
"         认行为。


"                                                    *'g:ctrlp_follow_symlinks'*
"如果非0，当列出文件时CtrlP会跟随链接: >
"  let g:ctrlp_follow_symlinks = 0
"<
"  0 - 不要跟随链接。
"  1 - 跟随但是忽略内部循环的链接，避免重复。
"  2 - 无差别的跟随所有链接。

"注意: 当命令使用 |g:ctrlp_user_command| 定义时该选项无效。

 "                                                       *'g:ctrlp_lazy_update'*
"设置为1将开启延迟更新特性：只在输入停止一个确定的时间后才更新匹配窗口: >
"  let g:ctrlp_lazy_update = 0
"<
"如果设置为1，在250毫秒后更新。如果大于1，数字会被作为延迟时间使用。

 "                                                     *'g:ctrlp_default_input'*
"设置为1将为提示符面板提供当前文件的相对路径作为种子: >
"  let g:ctrlp_default_input = 0
"<
"如果不指定1或0，如果选项的值是字符串，会被用来作为默认输入: >
"  let g:ctrlp_default_input = 'anystring'
"<

"                                                             *'g:ctrlp_abbrev'*
"定义可以在提示面包内被扩展（内部的或者可见的）的输入缩写: >
"  let g:ctrlp_abbrev = {}
"<
"例子: >
"  let g:ctrlp_abbrev = {
"    \ 'gmode': 'i',
"    \ 'abbrevs': [
"      \ {
"        \ 'pattern': '^cd b',
"        \ 'expanded': '@cd ~/.vim/bundle',
"        \ 'mode': 'pfrz',
"      \ },
"      \ {
"        \ 'pattern': '\(^@.\+\|\\\@<!:.\+\)\@<! ',
"        \ 'expanded': '.\{-}',
"        \ 'mode': 'pfr',
"      \ },
"      \ {
"        \ 'pattern': '\\\@<!:.\+\zs\\\@<! ',
"        \ 'expanded': '\ ',
"        \ 'mode': 'pfz',
"      \ },
"      \ ]
"    \ }
"<
"字符串 'pattern' 是使用正则表达式来匹配输入的匹配模式。扩展后就像扩展后的字符串
"在提示符面板中被输入了一样。

"对于 'gmode' （可选的）:
"  i - 内部扩展（默认）。
"  t - 插入扩展结果到提示符面板，就像你自己输入的一样。
"  k - 当非关键字的字符被输入时，插入扩展结果到提示符面板。只在"t"也出现时生效。

"对于 'mode' （对于每个条目，可选的）:
"  f - 只应用于文件名模式。
"  p - 只应用于全路径模式。
"  r - 只应用于正则表达式模式。
"  z - 只应用于模糊模式。
"  n - 只应用于使用 <c-y> 创建新文件时（使用扩展后的字符串作为文件名）。
"  c - 当使用 <tab> 自动补全目录名时（在自动补全之前立即扩展模式）。
"  <empty> 或者未定义 - 总是启用。

"注意: 缩写条目按顺序求值，后求值的条目会覆盖先求值的条目；当 'gmode' 为"t"时，
"包括他自己。

"                                                           *'g:ctrlp_key_loop'*
"一个实验性的特性。设置该选项为1将为多字节字符开启输入事件循环: >
"  let g:ctrlp_key_loop = 0
"<
"注意 #1: 当设置时，该选项会重置 |g:ctrlp_lazy_update| 选项。

"注意 #2: 你可以在提示符面板使用自定义的按键绑定切换这个特性: >
"  let g:ctrlp_prompt_mappings = { 'ToggleKeyLoop()': ['<F3>'] }
"<

"                                                    *'g:ctrlp_prompt_mappings'*
"使用该选项来自定义CtrlP的提示窗口内的按键绑定为你喜欢的方式。你只需要保留你改
"变值（在[]内部）的行: >
"  let g:ctrlp_prompt_mappings = {
"    \ 'PrtBS()':              ['<bs>', '<c-]>'],
"    \ 'PrtDelete()':          ['<del>'],
"    \ 'PrtDeleteWord()':      ['<c-w>'],
"    \ 'PrtClear()':           ['<c-u>'],
"    \ 'PrtSelectMove("j")':   ['<c-j>', '<down>'],
"    \ 'PrtSelectMove("k")':   ['<c-k>', '<up>'],
"    \ 'PrtSelectMove("t")':   ['<Home>', '<kHome>'],
"    \ 'PrtSelectMove("b")':   ['<End>', '<kEnd>'],
"    \ 'PrtSelectMove("u")':   ['<PageUp>', '<kPageUp>'],
"    \ 'PrtSelectMove("d")':   ['<PageDown>', '<kPageDown>'],
"    \ 'PrtHistory(-1)':       ['<c-n>'],
"    \ 'PrtHistory(1)':        ['<c-p>'],
"    \ 'AcceptSelection("e")': ['<cr>', '<2-LeftMouse>'],
"    \ 'AcceptSelection("h")': ['<c-x>', '<c-cr>', '<c-s>'],
"    \ 'AcceptSelection("t")': ['<c-t>'],
"    \ 'AcceptSelection("v")': ['<c-v>', '<RightMouse>'],
"    \ 'ToggleFocus()':        ['<s-tab>'],
"    \ 'ToggleRegex()':        ['<c-r>'],
"    \ 'ToggleByFname()':      ['<c-d>'],
"    \ 'ToggleType(1)':        ['<c-f>', '<c-up>'],
"    \ 'ToggleType(-1)':       ['<c-b>', '<c-down>'],
"    \ 'PrtExpandDir()':       ['<tab>'],
"    \ 'PrtInsert("c")':       ['<MiddleMouse>', '<insert>'],
"    \ 'PrtInsert()':          ['<c-\>'],
"    \ 'PrtCurStart()':        ['<c-a>'],
"    \ 'PrtCurEnd()':          ['<c-e>'],
"    \ 'PrtCurLeft()':         ['<c-h>', '<left>', '<c-^>'],
"    \ 'PrtCurRight()':        ['<c-l>', '<right>'],
"    \ 'PrtClearCache()':      ['<F5>'],
"    \ 'PrtDeleteEnt()':       ['<F7>'],
"    \ 'CreateNewFile()':      ['<c-y>'],
"    \ 'MarkToOpen()':         ['<c-z>'],
"    \ 'OpenMulti()':          ['<c-o>'],
"    \ 'PrtExit()':            ['<esc>', '<c-c>', '<c-g>'],
"    \ }
"<
"注意: 如果按 <bs> 后光标向左移动一个字符而不是删除一个字符，在你的.vimrc中添加
"下面的设置来禁用插件默认的 <c-h> 绑定: >
"  let g:ctrlp_prompt_mappings = { 'PrtCurLeft()': ['<left>', '<c-^>'] }
"<

"----------------------------------------
"MRU mode options:~

"                                                           *'g:ctrlp_mruf_max'*
"指定你希望CtrlP记录的最近打开的文件历史的数目: >
"  let g:ctrlp_mruf_max = 250
"<

"                                                       *'g:ctrlp_mruf_exclude'*
"你不希望CtrlP记录的文件。使用正则表达式来指定模式: >
"  let g:ctrlp_mruf_exclude = ''
"<
"例子: >
"  let g:ctrlp_mruf_exclude = '/tmp/.*\|/temp/.*' " MacOSX/Linux
"  let g:ctrlp_mruf_exclude = '^C:\\dev\\tmp\\.*' " Windows
"<

"                                                       *'g:ctrlp_mruf_include'*
"如果你想让CtrlP只记录某些文件，在这里指定: >
"  let g:ctrlp_mruf_include = ''
"<
"例子: >
"  let g:ctrlp_mruf_include = '\.py$\|\.rb$'
"<
"                                                       *'g:ctrlp_tilde_homedir'*
v将这个选项设置为1来把所有的 MRU 文件路径中 $HOME 目录下的 $HOME/$filepath 保存
"为 ~/$filepath ，而不是 $HOME/$filepath : >
"  let g:ctrlp_tilde_homedir = 0
v<
"注意: 对所有通过 :CtrlPBookmarkDirAdd! 保存的也有效

"                                                      *'g:ctrlp_mruf_relative'*
"设置该选项为1将只显示在当前工作目录内的最近最多使用文件: >
"  let g:ctrlp_mruf_relative = 0
"<
"注意: 你可以在提示符面板使用自定义的按键绑定切换这个特性: >
"  let g:ctrlp_prompt_mappings = { 'ToggleMRURelative()': ['<F2>'] }
"<

"                                                 *'g:ctrlp_mruf_default_order'*
"设置该选项为1将在最近最多使用模式搜索时禁用排序: >
"  let g:ctrlp_mruf_default_order = 0
"<

"                                                *'g:ctrlp_mruf_case_sensitive'*
"将该选项和你的文件系统大小写敏感性保持一致来避免重复的最近最多使用条目: >
"  let g:ctrlp_mruf_case_sensitive = 1
"<

"                                                *'g:ctrlp_mruf_save_on_update'*
"设置该选项为0将不会每当有一个新条目增加就把最近最多使用列表保存到磁盘文件，而
"是在退出Vim时才保存: >
"  let g:ctrlp_mruf_save_on_update = 1
"<

"                                                *'g:ctrlp_mruf_exclude_nomod'*
"将这个选项设置为1来禁止添加不可编辑的缓冲区，例如帮助文件，到 MRU 列表: >
"  let g:ctrlp_mruf_exclude_nomod = 0
"<
"----------------------------------------
"高级选项:~

"                                                          *'g:ctrlp_open_func'*
"使用一个自定义函数来打开选定的文件: >
"  let g:ctrlp_open_func = {}
"<
"例子: >
"  let g:ctrlp_open_func = {
"    \ 'files'     : 'Function_Name_1',
"    \ 'buffers'   : 'Function_Name_2',
"    \ 'mru files' : 'Function_Name_3',
"    \ }
"<
"函数结构: >
"  function! Function_Name(action, line)
"    " 参数:
"    " |
"    " +- a:action : 打开的动作:
"    " |             + 'e' : 用户按下 <cr>  (默认)
"    " |             + 'h' : 用户按下 <c-x> (默认)
"    " |             + 'v' : 用户按下 <c-v> (默认)
"    " |             + 't' : 用户按下 <c-t> (默认)
"    " |             + 'x' : 用户使用 <c-o> 终端对话框 (默认) 选择"e[x]ternal"。
"    " |
"    " +- a:line   : 选择的文件。

"  endfunction
"<
"注意: 当使用<c-z> 和 <c-o>打开多个文件时无效。

"例子: 当 <c-t> 被按下时在默认浏览器中打开HTML文件，否则在Vim中打开 >
"  function! HTMLOpenFunc(action, line)
"    if a:action =~ '^[tx]$' && fnamemodify(a:line, ':e') =~? '^html\?$'

"      " 获取文件名
"      let filename = fnameescape(fnamemodify(a:line, ':p'))

"      " 关闭CtrlP
"      call ctrlp#exit()

"      " 打开文件
"      silent! execute '!xdg-open' filename

"    elseif a:action == 'x' && fnamemodify(a:line, ':e') !~? '^html\?$'

"      " 不是HTML文件，再次模拟 <c-o> 按键并且等待新的输入
"      call feedkeys("\<c-o>")

"    else

"      " 使用CtrlP的默认的打开文件的函数
"      call call('ctrlp#acceptfile', [a:action, a:line])

"    endif
"  endfunction

"  let g:ctrlp_open_func = { 'files': 'HTMLOpenFunc' }
"<

"                                                        *'g:ctrlp_status_func'*
"为CtrlP窗口使用自定义的状态栏: >
"  let g:ctrlp_status_func = {}
"<
"例子: >
"  let g:ctrlp_status_func = {
"    \ 'main': 'Function_Name_1',
"    \ 'prog': 'Function_Name_2',
"    \ }
"<
"函数结构: >
"  " 主状态栏
"  function! Function_Name_1(focus, byfname, regex, prev, item, next, marked)
"    " 参数:
"    " |
"    " +- a:focus   : 提示符面板的焦点: "prt" 或者 "win"。
"    " |
"    " +- a:byfname : 在文件名模式还是全路径模式: "file" 或者 "path"。
"    " |
"    " +- a:regex   : 是否在正则表达式模式: 1 or 0。
"    " |
"    " +- a:prev    : 前一个搜索模式。
"    " |
"    " +- a:item    : 当前的搜索模式。
"    " |
"    " +- a:next    : 下一个搜索模式。
"    " |
"    " +- a:marked  : 被标记文件的数目，或者一个逗号分隔的被标记的文件名列表。

"    return full_statusline
"  endfunction

"  " 状态栏进度条
"  function! Function_Name_2(str)
"    " a:str : 一个当前已扫描的文件数，或者一个当前扫描目录和用户命令的字符串。

"    return full_statusline
"  endfunction
"<
"一个可用的例子，参见 https://gist.github.com/1610859 。

"                                                        *'g:ctrlp_buffer_func'*
"指定一个会在启动或者退出CtrlP缓冲区时被调用的函数: >
"  let g:ctrlp_buffer_func = {}
"<
"例子: >
"  let g:ctrlp_buffer_func = {
"    \ 'enter': 'Function_Name_1',
"    \ 'exit':  'Function_Name_2',
"    \ }
"<

"                                                         *'g:ctrlp_match_func'*
"为CtrlP设置一个额外的模糊匹配函数: >
"  let g:ctrlp_match_func = {}
"<
"例子: >
"  let g:ctrlp_match_func = { 'match': 'Function_Name' }
"<
"函数结构: >
"  function! Function_Name(items, str, limit, mmode, ispath, crfile, regex)
"    " 参数:
"    " |
"    " +- a:items  : 搜索条目的全列表。
"    " |
"    " +- a:str    : 用户输入的字符串。
"    " |
"    " +- a:limit  : 匹配窗口的最大高度。可以用来限制返回的条目数量。
"    " |
"    " +- a:mmode  : 在匹配模式。可以是下列字符串之一:
"    " |             + "full-line": 匹配整行。
"    " |             + "filename-only": 只匹配文件名。
"    " |             + "first-non-tab": 匹配到第一个制表符。
"    " |             + "until-last-tab": 匹配到最后一个制表符。
"    " |
"    " +- a:ispath : 搜索文件，缓冲区，最近最多使用，混合，目录和rtscript模.
"    " |             式时为1。其它为0。
"    " |
"    " +- a:crfile : 当前窗口中的文件。当a:ispath为1时应该被搜索结果排除在外
"    " |
"    " +- a:regex  : 是否在正则表达式模式: 1 or 0.

"    return list_of_matched_items
"  endfunction
"<

"注意: 你可以通过 { 'arg_type': 'dict' } 扩展上面的任何选项，这样就可以通过
"一个字典类型的参数来传递所有的函数参数。使用参数名作为字典的键值。

"例子: >
"  let g:ctrlp_status_func = {
"    \ 'arg_type' : 'dict',
"    \ 'enter': 'Function_Name_1',
"    \ 'exit':  'Function_Name_2',
"    \ }

"  function! Function_Name_1(dict)
"    " where dict == {
"    " \ 'focus':   value,
"    " \ 'byfname': value,
"    " \ 'regex':   value,
"    " \ ...
"    " }
"  endfunction
"<
"                                                          *ctrl默认值*
"另外，你可以使用下面的方式来改变默认值。
"例子: >
"  let g:ctrlp_path_nolim = 1

"这样可以让无限制模式匹配“路径”类型。
"===============================================================================
"命令                                                           *ctrlp-commands*

"                                                                       *:CtrlP*
":CtrlP [起始目录]
"   用文件搜索模式打开CtrlP。

"   如果没有给定参数，|g:ctrlp_working_path_mode| 会被用来决定起始目录。

"   在输入时你可以使用 <tab> 自动补全[起始目录]。

"                                                                 *:CtrlPBuffer*
":CtrlPBuffer
"   用缓冲区搜索模式打开CtrlP。

"                                                                    *:CtrlPMRU*
":CtrlPMRU
"   用最近最多使用模式打开CtrlP。

"                                                               *:CtrlPLastMode*
":CtrlPLastMode [--dir]
"   用上一次使用的模式打开CtrlP。当提供了"--dir"参数，也重用上一次的工作目录。

"                                                                   *:CtrlPRoot*
":CtrlPRoot
"    行为类似使用了 |g:ctrlp_working_path_mode| = 'r' 并且忽略了该变量的当前值的
"    |:CtrlP| 命令。

"                                                             *:CtrlPClearCache*
":CtrlPClearCache
"   清除当前工作目录的缓存。和在CtrlP内按 <F5> 效果一样。
"   使用 |g:ctrlp_use_caching| 来启用或禁用缓存。

"                                                         *:CtrlPClearAllCaches*
":CtrlPClearAllCaches
"   删除在 |g:ctrlp_cache_dir| 中定义的缓存目录中的所有缓存文件。

"-------------------------------------------------------------------------------
"由扩展提供的命令参见 |ctrlp-extensions| 。

"===============================================================================
"按键绑定                                                        *ctrlp-mappings*

"                                                                *'ctrlp-<c-p>'*
"<c-p>
"   普通模式 |Normal| 下默认以文件搜索模式打开CtrlP提示符面板。

"----------------------------------------
"已经在提示符面板中:~

"  <c-d>
"    在全路径搜索和文件名搜索间切换。
"    注意: 在文件名搜索模式，提示符面板的提示符是'>d>'，而不是'>>>'

"  <c-r>                                                    *'ctrlp-fullregexp'*
"    在字符串搜索模式和正则表达式模式之间切换。
"    注意: 在全正则表达式模式，提示符面板的提示符是'r>>'，而不是'>>>'

"    详细参见: |input-formats| （指引）和 |g:ctrlp_regexp_search| 选项。

"  <c-f>, 'forward' 前进
"  <c-up>
"    切换到序列里面的 'next' 后一个搜索模式。

"  <c-b>, 'backward' 后退
"  <c-down>
"    切换到序列里面的 'previous' 前一个搜索模式。

"  <tab>                                                *'ctrlp-autocompletion'*
"    自动补全在提示符面板的当前工作路径中的目录名。

"  <s-tab>
"    在匹配窗口和提示符面板之间切换焦点。

"  <esc>,
"  <c-c>
"    退出CtrlP。

"移动:~

"  <c-j>,
"  <down>
"    向下移动。

"  <c-k>,
"  <up>
"    向上移动。

"  <c-a>
"    移动光标到提示符面板的 'start' 开头。

"  <c-e>
"    移动光标到提示符面板的 'end' 末尾。

"  <c-h>,
"  <left>,
"  <c-^>
"    向左 'left' 移动一个字符。

"  <c-l>,
"  <right>
"    向右 'right' 移动一个字符。

"编辑:~

"  <c-]>,
"  <bs>
"    删除前一个字符。

"  <del>
"    删除当前字符。

"  <c-w>
"    删除前一个单词。

"  <c-u>
"    清除输入。

"浏览输入历史:~

"  <c-n>
"    提示符面板历史里的下一个字符串。

"  <c-p>
"    提示符面板历史里的上一个字符串。

"打开/创建文件:~

"  <cr>
"    如果可能的话在 'current' 当前窗口打开选择的文件。

"  <c-t>
"    在 'tab' 新标签打开选择的文件。
"    Open the selected file in a new 'tab'.

"  <c-v>
"    在 'vertical' 竖直分割窗口打开选择的文件。

"  <c-x>,
"  <c-cr>,
"  <c-s>
"    在 'horizontal' 水平分割窗口打开选择的文件。

"  <c-y>
"    创建一个新文件和它的父目录。

"打开多个文件:~

"  <c-z>
"    - 标记/取消标记一个被 <c-o> 打开的文件。
"    - 标记/取消标记一个被 <c-y> 在它的目录被创建的文件。

"  <c-o>
"    - 打开被 <c-z> 标记的文件。
"    - 当没有文件被 <c-z> 标记时，使用下列选项打开一个终端对话框:

"      打开被选择的文件:
"        t - 在新标签页中打开。
"        v - 在一个竖直分割窗口中。
"        h - 在一个水平分割窗口中。
"        r - 在当前窗口中打开。
"        i - 在隐藏的缓冲区中。
"        x - （可选的）使用 |g:ctrlp_open_func| 中定义的函数。

"      其它选项 （未显示）:
"        a - 标记匹配窗口中的所有文件。
"        d - 改变CtrlP的工作目录到被选择的文件的目录并切换到文件搜索模式。

"功能按键绑定:~

"  <F5>
"    - 刷新匹配窗口并且清除当前目录的缓存。
"    - 从最近最多使用中移除被删除的文件。

"  <F7>
"    - 清除最近最多使用列表。
"    - 删除被 <c-z> 标记的最近最多使用条目。

""粘贴:~
"
""  <Insert>,                                                   *'ctrlp-pasting'*
""  <MiddleMouse>
""    将剪贴板中的文本粘贴到提示符窗口中。

""  <c-\>
""    打开一个终端对话框来粘贴 <cword>， <cfile>，搜索寄存器的文本，上一次可视
"    化模式的选择，剪贴板或者任何寄存器到提示符面板中。

"使用 |g:ctrlp_prompt_mappings| 选择你自己的绑定。

"----------------------------------------
"当焦点在匹配窗口中时（使用 <s-tab> 来切换）:~

"  a-z
"  0-9
"  ~^-=;`',.+!@#$%&_(){}[]
"    在匹配第一个字符的行中循环。

"===============================================================================
"输入格式                                                  *ctrlp-input-formats*

"提示符面板的输入格式:~

"a)  字符串。

"    例如: 'abc' 被内部理解为 'a[^a]\{-}b[^b]\{-}c'

"b)  在正则表达式模式，输入字符串被按照Vim的正则表达式模式 |pattern| 来对待，不
"    进行任何修改。"

"    例如: 'abc\d*efg' 会被解读为 'abc\d*efg'。

"    如何启用正则表达式模式参见 |ctrlp-fullregexp| （按键绑定）和 
"    |g:ctrlp_regexp_search| （选项）。

"c)  字符串末尾使用一个冒号':'跟随一个Vim命令来在打开那个文件后执行该命令。如果
"    你需要使用':'的字面意思，使用反斜杠转义'\:'。但打开多个文件时，命令会在每
"    个打开文件上执行。

"   例如: 使用':45'跳转到第45行。
"
"          使用':/any\:string'跳转到'any:string'第一次出现的地方。

"          使用':+setf\ myfiletype|50'来设置文件类型为 'myfiletype'，然后跳转
"          到第50行。

"          使用':diffthis'当打开多个文件时在前四个文件上调用 |:diffthis| 。

"    参见: Vim的 |++opt| 和 |+cmd|.

"d)  提交两个点号 '..' 来进入上级目录。如果想进入向上多级目录，每多一级使用一个
"    额外的点号:
">
"         输入         解释为
"         ..           ../
"         ...          ../../
"         ....         ../../../
"<
"    注意: 如果父目录很大并且没有被缓存，可能会很慢。

"    你可以使用'@cd path/'来改变CtrlP的工作目录为path/。使用'@cd %:h'来改变为当
"    前文件的目录。

"e)  相似的，提交'/'或者'\'来查找或者跳转到项目的根目录。

"    如果项目很大，使用版本控制系统的列出命令来寻找文件可能会加速初始化扫描。（
"    更多细节参见 |g:ctrlp_user_command| )。

"    注意: d) 和 e) 只在文件，目录和混合模式生效。

"f)  输入一个不存在的文件名并且按下 <c-y> 来创建文件。如果使用 <c-z> 标记了一个
"    文件，将会在被标记的文件的目录下创建这个新文件。

"    例如: 使用 'newdir/newfile.txt' 会创建一个名为'newdir'的目录和一个名为
"          'newfile.txt'的文件。

"          如果一个条目'some/old/dirs/oldfile.txt'被 <c-z> 标记，然后 'newdir'
"          和'newfile.txt'会在'some/old/dirs'下被创建。最终的路径会像下面这样
"          'some/old/dirs/newdir/newfile.txt'.

"    注意: 在Windows下使用 '\' 代替 '/' （如果 |'shellslash'| 选项没有设置）。

"g)  在文件名模式（使用 <c-d> 切换）下，你可以使用被逗号分隔的一个主要的模式和
"    一个改善的模式。两个模式在正则表达式模式下像（a）或（b）那样工作。

"h)  使用?打开帮助文件。

"===============================================================================
"扩展                                                         *ctrlp-extensions*

"扩展是可选的。把它的名字添加到变量g:ctrlp_extensions中来开启扩展: >
"  let g:ctrlp_extensions = ['tag', 'buffertag', 'quickfix', 'dir', 'rtscript',
"                          \ 'undo', 'line', 'changes', 'mixed', 'bookmarkdir']
"<
"扩展的名字在变量中出现的顺序会是在使用命令 <c-f>， <c-b> 切换时扩展在状态栏中出
"现的顺序。

"可用的扩展:~

"                                                                    *:CtrlPTag*
"  * 标记模式:~
"    - 名称: 'tag'
"    - 命令: ":CtrlPTag"
"    - 在一个生成的标记文件中搜索标签，跳转到标签定义。使用Vim的 |'tags'| 来指定
"      标签文件的位置和名称。
"      例如: set tags+=doc/tags
"                                                                 *:CtrlPBufTag*
"                                                              *:CtrlPBufTagAll*
"  * 缓冲区标签模式:~
"    - 名称: 'buffertag'
"    - 命令: ":CtrlPBufTag [缓冲区]"，
"                ":CtrlPBufTagAll"。
"    - 在当前缓冲区或者所有列出的缓冲区中搜索标签并且跳转到定义。需要
"      |exuberant_ctags| 或者兼容的程序。

"                                                               *:CtrlPQuickfix*
"  * 快速修复模式:~
"    - 名称: 'quickfix'
"    - 命令: ":CtrlPQuickfix"
"    - 在当前的快速修复错误列表中搜索条目并且跳转过去。

"                                                                    *:CtrlPDir*
"  * 目录模式:~
"    - 名称: 'dir'
"    - 命令: ":CtrlPDir [起始muu]"
"    - 搜索目录并且将其作为工作目录。
"    - 按键绑定:
"      + <cr> 为CtrlP修改工作目录并且保持打开状态。
"      + <c-t> 修改全局的工作目录（退出）。
"      + <c-v> 为当前窗口修改工作目录（退出）。
"      + <c-x> 修改全局工作目录为CtrlP的当前工作目录（退出）。

"                                                                    *:CtrlPRTS*
"  * 运行时脚本模式:~
"    - 名称: 'rtscript'
"    - 命令: ":CtrlPRTS"
"    - 在运行时路径中寻找文件（vimscripts, docs, snippets...）。

"                                                                   *:CtrlPUndo*
"  * 撤销模式:~
"    - 名称: 'undo'
"    - 命令: ":CtrlPUndo"
"    - 浏览撤销历史。

"                                                                   *:CtrlPLine*
"  * 行模式:~
"    - 名称: 'line'
"    - 命令: ":CtrlPLine [缓冲区]"
"    - 在所有列出的缓冲区或者在指定的 [buffer] 缓冲区内搜索一行内容。
"
"                                                                 *:CtrlPChange*
"                                                              *:CtrlPChangeAll*
"  * 修改列表模式:~
"    - 名称: 'changes'
"    - 命令: ":CtrlPChange [缓冲区]",
"            ":CtrlPChangeAll".
"    - 在当前缓冲区或者在所有列出的缓冲区内搜索最近的修改并跳转。
"
"                                                                  *:CtrlPMixed*
"  * 混合模式:~
"    - 名称: 'mixed'
"    - 命令: ":CtrlPMixed"
"    - 同时在文件，缓冲区和最近最多修改中搜索。

"                                                            *:CtrlPBookmarkDir*
"                                                         *:CtrlPBookmarkDirAdd*
"  * 书签目录模式:~
"    - 名称: 'bookmarkdir'
"    - 命令: ":CtrlPBookmarkDir",
"            ":CtrlPBookmarkDirAdd [目录] [标题]".
"            ":CtrlPBookmarkDirAdd! [目录] [标题]".
"    - 搜索一个被书签标记的目录并将其作为工作目录。
"    - 以指定的[标题]添加[目录]到 CtrlPBookmarkDir 中，如果没有给出[标题]或
"      者[目录]，会请求用户输入。
"    - 以指定的[标题]添加[目录]到 CtrlPBookmarkDir 中，如果没有给出目录，则
"      默认为当前目录( [CWD] )，如果没有给出[标题] ，会请求用户输入。

"      最新的用来添加所有最近使用过的目录到 CtrlPBookmarkDir 列表中的自动命令
"      如下
"      >
"      augroup CtrlPDirMRU
"        autocmd!
"        autocmd FileType * if &modifiable | execute 'silent CtrlPBookmarkDirAdd! %:p:h' | endif
"      augroup END
"<

"    - 按键绑定:
"      + <cr> 为CtrlP修改工作目录并且保持打开状态，并且切换到文件搜索模式。
"      + <c-x> 修改全局的工作目录（退出）。
"      + <c-v> 为当前窗口修改工作目录（退出）。
"      + <F7>
"        - 清除书签列表。
"        - 删除被 <c-z> 标记的书签条目。

"----------------------------------------
"缓冲区标记模式选项:~

"                                                   *'g:ctrlp_buftag_ctags_bin'*
"如果ctags没有在环境变量中配置，使用该选项来指定它的位置: >
"  let g:ctrlp_buftag_ctags_bin = ''
"<

"                                                   *'g:ctrlp_buftag_systemenc'*
"将该选项与你的操作系统的编码（非Vim的）保持一致。默认值使用Vim的全局
"|'encoding'| 选项: >
"  let g:ctrlp_buftag_systemenc = &encoding
"<

"                                                       *'g:ctrlp_buftag_types'*
"使用该选项来在ctags, jsctags...中为指定的文件格式设置参数: >
"  let g:ctrlp_buftag_types = ''
"<
"例子: >
"  let g:ctrlp_buftag_types = {
"    \ 'erlang'     : '--language-force=erlang --erlang-types=drmf',
"    \ 'javascript' : {
"      \ 'bin': 'jsctags',
"      \ 'args': '-f -',
"      \ },
"    \ }
"<

"===============================================================================
"自定义                                                    *ctrlp-customization*

"高亮:~
"  * CtrlP缓冲区的设置:
"    CtrlPNoEntries : 当没有匹配被发现时的消息（错误）。
"    CtrlPMatch     : 匹配模式（标识）。
"    CtrlPLinePre   : 匹配窗口的行前缀'>'。
"    CtrlPPrtBase   : 提示符窗口的基础（注释）。
"    CtrlPPrtText   : 提示符窗口的文本 （|hl-Normal|）。
"    CtrlPPrtCursor : 提示符窗口的光标在文本上移动时（常量）。

"  * 在扩展中:
"    CtrlPTabExtra  : 每一行中不匹配的部分（注释）。
"    CtrlPBufName   : 条目所属的缓冲区名称（|hl-Directory|）。
"    CtrlPTagKind   : 缓冲区标签模式中标签的类型（|hl-Title|）。
"    CtrlPqfLineCol : 快速修复模式中行和列的序号（注释）。
"    CtrlPUndoT     : 撤销模式的流逝时间（|hl-Directory|）。
"    CtrlPUndoBr    : 撤销模式的方括号（注释）。
"    CtrlPUndoNr    : 撤销模式的方括号中的数字（字符串）。
"    CtrlPUndoSv    : 文件被保存的点（注释）。
"    CtrlPUndoPo    : 撤销树中的当前位置（|hl-Title|）。
"    CtrlPBookmark  : 书签的名称（标识）。

"状态栏:~
"  * 高亮组:
"    CtrlPMode1 : 'file' 或 'path' 或 'line'，和当前模式（字符）。
"    CtrlPMode2 : 'prt' 或 'win'， 'regex'，工作目录 |hl-LineNr| 。
"    CtrlPStats : 扫描状态（函数）。

"  重新构建状态栏，参见 |g:ctrlp_status_func| 。

"===============================================================================
"其它选项                                          *ctrlp-miscellaneous-configs*

"* 为 |g:ctrlp_user_command| 使用 |wildignore| :
">
"  function! s:wig2cmd()
"    " 修改wildignore为空格或者|分隔的组
"    " 例如: .aux .out .toc .jpg .bmp .gif
"    " 或者  .aux$\|.out$\|.toc$\|.jpg$\|.bmp$\|.gif$
"    let pats = ['[*\/]*\([?_.0-9A-Za-z]\+\)\([*\/]*\)\(\\\@<!,\|$\)','\\\@<!,']
"    let subs = has('win32') || has('win64') ? ['\1\3', ' '] : ['\1\2\3', '\\|']
"    let expr = substitute(&wig, pats[0], subs[0], 'g')
"    let expr = substitute(expr, pats[1], subs[1], 'g')
"    let expr = substitute(expr, '\\,', ',', 'g')

 "    " 设置用户命令选项
 "  let g:ctrlp_user_command = has('win32') || has('win64')
 "     \ ? 'dir %s /-n /b /s /a-d | findstr /V /l "'.expr.'"'
 "     \ : 'find %s -type f | grep -v "'.expr .'"'
 " endfunction

 " call s:wig2cmd()
"<
"（由 Rich Alesi <github.com/ralesi> 提交）

"* 一个独立的函数，设置项目的根目录为工作目录，如果没有找到根目录的话使用当前文
"* 件的父目录。
">
"  function! s:setcwd()
"    let cph = expand('%:p:h', 1)
"    if cph =~ '^.\+://' | retu | en
"    for mkr in ['.git/', '.hg/', '.svn/', '.bzr/', '_darcs/', '.vimprojects']
"      let wd = call('find'.(mkr =~ '/$' ? 'dir' : 'file'), [mkr, cph.';'])
"      if wd != '' | let &acd = 0 | brea | en
"    endfo
"    exe 'lc!' fnameescape(wd == '' ? cph : substitute(wd, mkr.'$', '.', ''))
"  endfunction

"  autocmd BufEnter * call s:setcwd()
"<
"(需要 Vim 7.1.299+)

"* 使用 |count| 来使用同样的按键绑定调用不同的命令:
">
"  let g:ctrlp_cmd = 'exe "CtrlP".get(["", "Buffer", "MRU"], v:count)'
"<
"===================================TagbarToggle=========================================================
nmap <F9> :TagbarToggle<CR>
" 启动时自动focus
let g:tagbar_autofocus = 1

" for ruby, delete if you do not need
"let g:tagbar_type_ruby = {
"    \ 'kinds' : [
"        \ 'm:modules',
"        \ 'c:classes',
"        \ 'd:describes',
"        \ 'C:contexts',
"        \ 'f:methods',
"        \ 'F:singleton methods'
"    \ ]
"\ }
"nmap <leader>tb :TagbarToggle<CR>  " \tb 打开tagbar窗口
"let g:tagbar_autofocus = 1

" 设置 tagbar 子窗口的位置出现在主编辑区的左边 
"let tagbar_left=1 
" 设置显示／隐藏标签列表子窗口的快捷键。速记：tag list 
"nnoremap <Leader>tl :TagbarToggle<CR> 
" 设置标签子窗口的宽度 
let tagbar_width=32 
" tagbar 子窗口中不显示冗余帮助信息 
let g:tagbar_compact=1
" 设置 ctags 对哪些代码元素生成标签
let g:tagbar_type_cpp = {
    \ 'kinds' : [
        \ 'd:macros:1',
        \ 'g:enums',
        \ 't:typedefs:0:0',
        \ 'e:enumerators:0:0',
        \ 'n:namespaces',
        \ 'c:classes',
        \ 's:structs',
        \ 'u:unions',
        \ 'f:functions',
        \ 'm:members:0:0',
        \ 'v:global:0:0',
        \ 'x:external:0:0',
        \ 'l:local:0:0'
     \ ],
     \ 'sro'        : '::',
     \ 'kind2scope' : {
         \ 'g' : 'enum',
         \ 'n' : 'namespace',
         \ 'c' : 'class',
         \ 's' : 'struct',
         \ 'u' : 'union'
     \ },
     \ 'scope2kind' : {
         \ 'enum'      : 'g',
         \ 'namespace' : 'n',
         \ 'class'     : 'c',
         \ 'struct'    : 's',
         \ 'union'     : 'u'
     \ }
\ }
"=========================================NERDTree=======================================================
" plugin - NERD_tree.vim 以树状方式浏览系统中的文件和目录

" :ERDtree 打开NERD_tree         :NERDtreeClose    关闭NERD_tree

" o 打开关闭文件或者目录         t 在标签页中打开

" T 在后台标签页中打开           ! 执行此文件

" p 到上层目录                   P 到根目录

" K 到第一个节点                 J 到最后一个节点

" u 打开上层目录                 m 显示文件系统菜单（添加、删除、移动操作）

" r 递归刷新当前目录             R 递归刷新当前根目录

autocmd vimenter * NERDTree
let g:NERDTreeQuitOnOpen=0
" show hidden files in NERDTree
let NERDTreeShowHidden=1
" Toggle NERDTree
nmap <F8> :NERDTreeToggle<CR>
" expand to the path of the file in the current buffer
nmap <silent> <leader>y :NERDTreeFind<cr>



" CtrlP ignore patterns
let g:ctrlp_custom_ignore = {
            \ 'dir': '\.git$\|node_modules$\|\.hg$\|\.svn$',
            \ 'file': '\.exe$\|\.so$'
            \ }

" search the nearest ancestor that contains .git, .hg, .svn
let g:ctrlp_working_path_mode = 2

" 使用 NERDTree 插件查看工程文件。设置快捷键，速记：file list
"nmap <Leader>fl :NERDTreeToggle<CR>
" 设置NERDTree子窗口宽度
let NERDTreeWinSize=32
" 设置NERDTree子窗口位置
"let NERDTreeWinPos="right"
" 显示隐藏文件
let NERDTreeShowHidden=1
" NERDTree 子窗口中不显示冗余帮助信息
let NERDTreeMinimalUI=1
" 删除文件时自动删除文件对应 buffer
let NERDTreeAutoDeleteBuffer=1



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
"{
	try
		" undo 历史保存路径 需要自己创建 mkdir -P ~/.vim_runtime/temp_dirs/undodir
    	set undodir=~/.vim_runtime/temp_dirs/undodir
    	" 开启保存 undo 历史功能
    	set undofile
	catch
	endtry
"}
"==================================================================================================
"==========================================YCM========================================================
let g:ycm_confirm_extra_conf = 1
"let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
"let g:ycm_global_ycm_extra_conf = '/Users/BLUE/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_seed_identifiers_with_syntax = 1
"set tags+=~/work/test/ctest/UPlayer_Refactoring_Tudou/tags
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
"其中，工程自身代码的标签可借助 indexer 插件自动生成自动引入，但由于 YCM 要求 tag 文件中必须含有 language:<X> 字段（ctags 的命令行参数 --fields 必须含有 l 选项），所有必须通过 indexer_ctagsCommandLineOptions 告知 indexer 调用 ctags 时注意生成该字段，具体设置参见“代码导航”章节；前面章节介绍过如何生成、引入 C++ 标准库的 tag 文件，设置成正确路径即可。另外，由于引入过多 tag 文件会导致 vim 变得非常缓慢，我的经验是，只引入工程自身（indexer 自动引入）和 C++ 标准库的标签（上面配置的最后一行）。
"===================================================================================================
"=======================================ultisnips===================================================
" Track the engine.
"Plugin 'SirVer/ultisnips'

" Snippets are separated from the engine. Add this if you want them:
"Plugin 'honza/vim-snippets'

" Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
" UltiSnips 的 tab 键与 YCM 冲突，重新设定
let g:UltiSnipsExpandTrigger="<leader><tab>"
let g:UltiSnipsJumpForwardTrigger="<leader><tab>"
let g:UltiSnipsJumpBackwardTrigger="<leader><s-tab>"
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
"这样，键入 ;ch 就能在实现文件和接口文件间切换，键入 ;sch 子窗口中将显示实现文件/接口文件。
"===================================================================================================
"============================================signature.vim=======================================================
"sudo git submodule add https://github.com/kshenoy/vim-signature.git bundle/signature.vim
"let g:SignatureMap = {
        \ 'Leader'             :  "m",
        \ 'PlaceNextMark'      :  "m,",
        \ 'ToggleMarkAtLine'   :  "m.",
        \ 'PurgeMarksAtLine'   :  "m-",
        \ 'DeleteMark'         :  "dm",
        \ 'PurgeMarks'         :  "mda",
        \ 'PurgeMarkers'       :  "m<BS>",
        \ 'GotoNextLineAlpha'  :  "']",
        \ 'GotoPrevLineAlpha'  :  "'[",
        \ 'GotoNextSpotAlpha'  :  "`]",
        \ 'GotoPrevSpotAlpha'  :  "`[",
        \ 'GotoNextLineByPos'  :  "]'",
        \ 'GotoPrevLineByPos'  :  "['",
        \ 'GotoNextSpotByPos'  :  "mn",
        \ 'GotoPrevSpotByPos'  :  "mp",
        \ 'GotoNextMarker'     :  "[+",
        \ 'GotoPrevMarker'     :  "[-",
        \ 'GotoNextMarkerAny'  :  "]=",
        \ 'GotoPrevMarkerAny'  :  "[=",
        \ 'ListLocalMarks'     :  "ms",
        \ 'ListLocalMarkers'   :  "m?"
        \ }
"常用的操作也就如下几类：
"书签设定。mx，设定/取消当前行名为 x 的标签；m,，自动设定下一个可用书签名，前面提说，独立书签名是不能重复的，在你已经有了多个独立书签，当想再设置书签时，需要记住已经设定的所有书签名，否则很可能会将已有的书签冲掉，这可不好，所以，vim-signature 为你提供了 m, 快捷键，自动帮你选定下一个可用独立书签名；mda，删除当前文件中所有独立书签。
"书签罗列。ms，罗列出当前文件中所有书签，选中后回车可直接跳转；
"书签跳转。mn，按行号前后顺序，跳转至下个独立书签；mp，按行号前后顺序，跳转至前个独立书签。书签跳转方式很多，除了这里说的行号前后顺序，还可以基于书签名字母顺序跳转、分类书签同类跳转、分类书签不同类间跳转等等。
"===================================================================================================
"=======================================vimprj.vim============================================================
"git submodule add https://github.com/vim-scripts/vimprj.git bundle/vimprj.vim
"===================================================================================================
"=======================================DfrankUtil.git============================================================
"sudo git submodule add https://github.com/vim-scripts/DfrankUtil.git bundle/DfrankUtil.vim
"===================================================================================================
"==========================================ndexer=========================================================
"sudo git submodule add https://github.com/vim-scripts/indexer.tar.gz.git bundle/indexer.vim
let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"
"===================================================================================================
"===========================================nerdcommenter========================================================
"sudo git submodule add https://github.com/scrooloose/nerdcommenter.git bundle/nerdcommenter.vim
"===================================================================================================
"============================================fswitch.git=======================================================
"sudo git submodule add https://github.com/derekwyatt/vim-fswitch.git bundle/vim-fswitch.vim
"===================================================================================================
"============================================vim-protodef.git=======================================================
"sudo git submodule add https://github.com/derekwyatt/vim-protodef.git bundle/vim-protodef.vim
" 设置 pullproto.pl 脚本路径
let g:protodefprotogetter='~/.vim/bundle/vim-protodef.vim/pullproto.pl'
 " 成员函数的实现顺序与声明顺序一致
let g:disable_protodef_sorting=1
"MyClass.cpp 中我键入 protodef 定义的快捷键 <leader>PP，自动生成了函数框架。
"===================================================================================================
"========================================easymotion===========================================================
"sudo git submodule add https://github.com/easymotion/vim-easymotion.git bundle/vim-easymotion
"easymotion 只做一件事：把满足条件的位置用 [A~Za~z] 间的标签字符标出来，找到你想去的位置再键入对应标签字符即可快速到达。比如，上面的例子，假设光标在行首，我只需键入 <leader><leader>fa （为避免与其他快捷键冲突，easymotion 采用两次 <leader> 作为前缀键），所有的字符 a 都被重新标记成 a、b、c、d、e、f 等等标签（原始内容不会改变），f 标签为希望移动去的位置，随即键入 f 即可到达。
"===================================================================================================
"==================================================minibufexpl.vim=================================================
"sudo git submodule add https://github.com/fholgado/minibufexpl.vim.git bundle/minibufexpl.vim
let g:miniBufExplorerAutoStart = 0
let g:miniBufExplBuffersNeeded = 0
let g:miniBufExplUseSingleClick = 0
"===================================================================================================
"==============================================ctrlsf.vim=====================================================
"ctrlsf.vim 后端调用 ack，所以你得提前自行安装。ctrlsf.vim 支持 ack 所有选项，要查找某个关键字（如，yangyang），你可以想让光标定位在该关键字上面，然后命令模式下键入


":CtrlSF
"将自动提取光标所在关键字进行查找，你也可以指定 ack 的选项

":CtrlSF -i -C 1 [pattern] /my/path/
"为方便操作，我设定了快捷键：

" 使用 ctrlsf.vim 插件在工程内全局查找光标所在关键字，设置快捷键。快捷键速记法：search in project
nnoremap <Leader>sp :CtrlSF<CR>

let g:ctrlsf_auto_close = 0

"In CtrlSF window:
"Enter - Open corresponding file of current line in the window which CtrlSF is launched from.
"<C-O> - Like Enter but open file in a horizontal split window.
"t - Like Enter but open file in a new tab.
"p - Like Enter but open file in a preview window.
"O - Like Enter but always leave CtrlSF window opening.
"T - Like t but focus CtrlSF window instead of new opened tab.
"q - Quit CtrlSF window.
"<C-J> - Move cursor to next match.
"<C-K> - Move cursor to previous match.
"===================================================================================================
"=========================================YankRing==========================================================
"sudo git submodule add https://github.com/vim-scripts/YankRing.vim.git bundle/YankRing.vim
"在vim裡面，copy只有一次的歷史紀錄， 
"如果希望能夠保留copy的歷史紀錄，就可以用這個plugin

"這個plugin也提供了非常好用「歷史替代」的功能。

"把這個plugin裝好之後，試試多copy幾段文字， 
"然後在normal mode按p貼上，然後再按<c-p>或<c-n>， 
"就會把剛才貼上的文字替換再前一次歷史的文字。
"非常好用，強力推薦。
"===================================================================================================
"==========================================bufexplorer=========================================================
"sudo git  submodule add https://github.com/vim-scripts/bufexplorer.zip.git bundle/bufexplorer
" plugin - bufexplorer.vim Buffers切换
" \be 全屏方式查看全部打开的文件列表
" \bv 左右方式查看   \bs 上下方式查看
map <leader>b :BufExplorer<cr>
let g:bufExplorerDefaultHelp=0
let g:bufExplorerDetailedHelp=0
let g:bufExplorerFindActive=1 
let g:bufExplorerShowDirectories=1
let g:bufExplorerShowNoName=1
let g:bufExplorerShowRelativePath=1
let g:bufExplorerSortBy='name'
"===================================================================================================
"=========================================mru.vim==========================================================
"sudo git submodule add https://github.com/vim-scripts/mru.vim.git bundle/mru.vim
"mkdir -p  ~/.vim_runtime/_vim_mru_files/
"touch ~/.vim_runtime/_vim_mru_files/_vim_mru_files
"default mru file is ~/.vim_mru_files
map <leader><leader>rf :MRU<CR>
let MRU_Exclude_Files = '^/tmp/.*\|^/var/tmp/.*'
"let MRU_File = '~/.vim_mru_files'
let MRU_Max_Entries = 1000
let MRU_Include_Files = '\.c$\|\.h$'
let MRU_Use_Current_Window = 1
let MRU_Auto_Close = 0
let MRU_Add_Menu = 0
let MRU_Max_Menu_Entries = 20
let MRU_Max_Submenu_Entries = 15
let MRU_Filename_Format={'formatter':'v:val', 'parser':'.*'}
"===================================================================================================
"===================================================================================================
" plugin - NERD_commenter.vim   注释代码用的，

" [count],cc 光标以下count行逐行添加注释(7,cc)

" [count],cu 光标以下count行逐行取消注释(7,cu)

" [count],cm 光标以下count行尝试添加块注释(7,cm)

" ,cA 在行尾插入 /* */,并且进入插入模式。 这个命令方便写注释。

" 注：count参数可选，无则默认为选中行或当前行

"-----------------------------------------------------------------

let NERDSpaceDelims=1       " 让注释符与语句之间留一个空格

let NERDCompactSexyComs=1   " 多行注释时样子更好看

"===================================================================================================
"===================================================================================================
let g:multi_cursor_next_key="\<C-s>"

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
" When searching try to be smart about cases 大小写不敏感
set smartcase
" Makes search act like search in modern browsers 输入时就开始找
set incsearch 
"使用鼠标
set mouse=a
"去掉输入错误的提示声音
set noeb
"ctags -R --c++-kinds=+p --fields=+iaS --extra=+q src
map <c-F12> :!CTags -R --c++-kinds=+p --fields=+iaSl --extra=+q .<CR><CR>
map <C-F12> :!ctags -R --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+liaS --extra=+q --language-force=c++


"中文帮助和中文菜单
"if version >= 603
set helplang=cn
"set encoding=utf-8
"endif
"set encoding=utf-8
"set termencoding=utf-8
"set fileencodings=utf-8
"========================================================================================================
" The default for 'backspace' is very confusing to new users, so change it to a
" more sensible value.  Add "set backspace&" to your ~/.vimrc to reset it.
set backspace+=indent,eol,start

" Disable localized menus for now since only some items are translated (e.g.
" the entire MacVim menu is set up in a nib file which currently only is
" translated to English).
"set langmenu=none

"========================================================================================================
":buffers   列示缓冲区状态
":buffer    编辑指定缓冲区
":ball  编辑所有缓冲区
":bnext 到下一缓冲区
":bprevious 到前一缓冲区
":blast 到最后一个缓冲区
":bfirst    到第一个缓冲区
":badd  增加缓冲区
":bdelete   删除缓冲区
":bunload   卸载缓冲区
":buffers   列示缓冲区状态
":buffer    编辑指定缓冲区
":ball  编辑所有缓冲区
":bnext 到下一缓冲区
":bprevious 到前一缓冲区
":blast 到最后一个缓冲区
":bfirst    到第一个缓冲区
":badd  增加缓冲区
":bdelete   删除缓冲区
":bunload   卸载缓冲区
":bwipe     彻底删除缓冲区

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
" 总是显示状态栏"取消底部状态栏显示。1为关闭，2为开启。
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
"在执行宏命令时，不进行显示重绘；在宏命令执行完成后，一次性重绘，以便提高性能。
set lazyredraw
" 设置状态栏主题风格
"cindent对c语法的缩进更加智能灵活，
"而shiftwidth则是在使用&lt;和&gt;进行缩进调整时用来控制缩进量。
"换行自动缩进，是按照shiftwidth值来缩进的
set cindent shiftwidth=4
"最基本的自动缩进
set autoindent shiftwidth=4
"比autoindent稍智能的自动缩进
set smartindent shiftwidth=4
"使用前导键加w来实现加速文件保存，来代替:w!加回车
nmap w :w!<CR>
"设置魔术匹配控制，可以通过:h magic查看更详细的帮助信息
set magic
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


"==============================================================================================================================================
"//在你的vimrc文件中增加像如下这样格式的key bindings  
"//格式为：  
"//模式 <快捷键> 要执行的命令  
"//模式：看下表，nmap为普通模式,imap为编辑模式  
"//C表示ctrl,A表示Alt,S表示Shift,<CR>表示回车  
   
"//比如下面这行表示在“正常||可视化||运算”模式下，按下Ctrl+W,则执行命令“:tabclose并回车”，就是关闭当前标签页  
"map <C-w> :tabclose<CR>  
  
"//又比如这行表示在“正常模式”下，按下Ctrl+t,  
"//则依次执行:browse(打开选择文件对话框） tabnew将选定的文件在新标签页中打开  
"nmap <C-t> :browse tabnew<CR>  
    
"//下面这行和上面一样，只是先用Esc从编辑模式切换到正常模式  
"imap <C-t> <Esc>:browse tabnew<CR>  
  

"比如使用以下命令，指定F10键来新建标签页：
":map <F10> <Esc>:tabnew<CR>
 
 
"其中：<Esc>代表Escape键；<CR>代表Enter键；而功能键则用<F10>表示。首先进入命令行模式，然后执行新建标签页的:tabnew命令，最后返回常规模式。
"同理：对于组合键，可以用<C-Esc>代表Ctrl-Esc；使用<S-F1>表示Shift-F1。对于Mac用户，可以使用<D>代表Command键。
"注意：Alt键可以使用<M-key>或<A-key>来表示。
"关于键盘符号的详细说明，请使用:h key-notation命令查看帮助信息  
  
"//下面这行和上面一样，只是先用Esc从编辑模式切换到正常模式  
"imap <C-t> <Esc>:browse tabnew<CR>  


"使用:map命令，可以将键盘上的某个按键与Vim的命令绑定起来。例如使用以下命令，可以通过F5键将单词用花括号括起来：

":map <F5> i{e<Esc>a}<Esc>
"其中：i{将插入字符{，然后使用Esc退回到命令状态；接着用e移到单词结尾，a}增加字符}，最后退至命令状态。在执行以上命令之后，光标定位在一个单词上（例如amount），按下F5键，这时字符就会变成{amount}的形式。

"Command命令	 Normal常规模式  Visual可视化模式	OperatorPending运算符模式		InsertOnly插入模式	CommandLine命令行模式
":map			y				y					y		
":nmap			y				
":vmap							y			
":omap												y		
":map!																			y					y
":imap																			y	
":cmap																								y

"如果想要取消一个映射，可以使用以下命令：

":unmap <F10>
"注意：必须为:unmap命令指定一个参数。如果未指定任何参数，那么系统将会报错，而不会取消所有的键盘映射。

"针对不同模式下的键盘映射，需要使用与其相对应的unmap命令。例如：使用:iunmap命令，取消插入模式下的键盘映射；而取消常规模式下的键盘映射，则需要使用:nunmap命令。

"如果想要取消所有映射，可以使用:mapclear命令。请注意，这个命令将会移除所有用户定义和系统默认的键盘映射。

"使用:map命令，可以列出所有键盘映射。其中第一列标明了映射在哪种模式下工作：

"标记	模式
"<space>	常规模式，可视化模式，运算符模式
"n	常规模式
"v	可视化模式
"o	运算符模式
"!	插入模式，命令行模式
"i	插入模式
"c	命令模式
"使用:map!命令，则只列出插入和命令行模式的映射。而:imap，:vmap，:omap，:nmap命令则只是列出相应模式下的映射。


"==============================================================================================================================================

"命令的组合
"同Vim下的其他命令一样，命令的名字往往由好几段组成。前缀作为命令本身的修饰符，微调命令的效果。
"对于map而言，可能有这么几种前缀

"nore
"表示非递归，见下面的介绍

"n
"表示在普通模式下生效

"v
"表示在可视模式下生效

"i
"表示在插入模式下生效

"c
"表示在命令行模式下生效

"Recursive Mapping
"递归的映射。其实很好理解，也就是如果键a被映射成了b，c又被映射成了a，如果映射是递归的，那么c就被映射成了b。

":map a b
":map c a
"对于c效果等同于

":map c b
"默认的map就是递归的。如果遇到[nore]这种前缀，比如:noremap，就表示这种map是非递归的。

"unmap
"unmap后面跟着一个按键组合，表示删除这个映射。

":unmap c
"那么在map生效模式下，c不再被映射到a上。

"同样，unmap可以加各种前缀，表示影响到的模式。

"mapclear
"mapclear直接清除相关模式下的所有映射。
"同样，mapclear可以加各种前缀，表示影响到的模式。

"这里列出常用的一些map命令，默认map命令影响到普通模式和可视模式。

":map :noremap :unmap :mapclear
":nmap :nnoremap :nunmap :nmapclear
":vmap :vnoremap :vunmap :vmapclear
":imap :inoremap :iunmap :imapclear
":cmap :cnoremap :cunmap :cmapclear


"==============================================================================================================================================
"//转换
"find . -name "*.h" -type f -exec sh -c "iconv --unicode-subst=FORMATSTRING -f GB18030 -t UTF8 {} > {}.hutf8" \;
"//把没用的bak文件删掉
"find . -name "*.h" -type f | xargs rm -rf
"//最后把转码之后的文件改名回正确名字，sed返回正确名字列表，在mv之前应该都是不存在的，例如xxx.h，这个时候应该还是xxx.h.hutf8 {}表示的就是要改成的最终文件名字
"find . -name "*.hutf8" -type f | sed 's/.hutf8$//' | xargs -I {} mv {}.hutf8 {}


"==============================================================================================================================================
"参照文章【1】【2】的办法，将vim打造成一个Python开发环境。文章中使用的是 pathogen + git 来管理 Vim 插件的。对这种方式还不太明白的同学可以参考【3】中的介绍。pathogen 改变了原先 Vim "只能把插件全部扔到 .vim 目录下的操作方式，使得各个插件可以以一个独立的文件夹存在于 .vim/bundle 目录中，添加和删除插件都变的非常清爽。使用 git 强大的子模块管理功能，可以实现方便的插件安装和自动升级。

"1. 准备工作
"创建.vim目录，以及其下的autoload和bundle目录。（如果先前已有.vim目录，可以先备份一下）
"$ mkdir ~/.vim/
"$ mkdir ~/.vim/{autoload,bundle}
"$ cd ~/.vim/
"$ git init
"如果Ubuntu中没有安装Git,需要首先安装Git【4】。

"2. 安装pathogen
"下载vim-pathogen【5】，将zip包中autoload下的pathogen.vim文件copy到 ~/.vim/autoload文件夹下。
"然后添加下面的命令到~/.vimrc文件中（.vimrc文件不存在的话，先创建.vimrc文件）。
"filetype off
"call pathogen#runtime_append_all_bundles()
"call pathogen#helptags()
"当运行pathogen命令的时候文件格式检测必须关闭，所以把filetype off放到最前面（UPTATED(20141022)）。
"这样，pathogen插件就安装好了。
"UPDATED(20141017):
"(1) 当按照本文设置完成后，使用vim时，会报错误：
"Error detected while processing /home/maxime/.vim/bundle/tasklist/plugin/tasklist.vim:
"line  369:
"E227: mapping already exists for \t
"错误原因是： tasklist will not map to <leader>t if a mapping to <Plug>TaskList is found.So you just need to create a mapping to <Plug>TaskList in your vimrc.
"解决方法是：在~/.vimrc文件中添加mapping【7】：
"nnoremap <leader>v <Plug>TaskList
"(2) 添加完mapping后，使用vim时，仍然会弹出以下命令行：
"Change pathogen#runtime_append_all_bundles() to pathogen#infect()
"Press ENTER or type command to continue
"原因：call pathogen#infect() which can be used in the latest version of pathogen now deals with this filetype problem (and is much easier to remember and type than runtime_append_all_bundles)【8】
"这是提示你 pathogen#runtime_append_all_bundles() 太老了，现在用 pathogen#infect() 替代它，而且比pathogen#runtime_append_all_bundles() 更容易记，还能少打好多字呢。
"所以你需要把上面设定中的 call pathogen#runtime_append_all_bundles()改为 pathogen#infect() 。
"UPTATED(20141022)
"当在vimrc中设置 设置语法高亮时，发现不起作用，如果将 filetype off 注掉，或者将其提至syntax on之前，语法高亮就会起作用。
"所以需要将filetype off 提至vimrc文件的最顶端。
"UPDATED（20141024）
"（1）关于pathogen为何要关闭filetype detection的原因，请参见【12】，同时也提供了解决办法，在 filetype off后，为不影响其他功能，在设置完pathogen后，再将filetype detection打开。
"（2）必须设置 filetype off，是因为Vim's file detection的一个bug,这个bug在 >Vim 7.3.430的版本中已修复了，因此如果vim的版本>Vim 7.3.430，则不必设置filetype off【13】。
"（3）为避免不必要的麻烦，我们将pathogen插件设置提前到vimrc的最开始。

"3. Git Submodule添加Plugin到Git Repository中
"Git Submodule的作用，简单来说就是可以将別人的 git 挂入到你目前 git 的任何位置。添加所有的vim plugins作为我们当前Repository的submodule。
"关于Git Submodule的详细教程，参考【6】。
"在~/.vim目录下执行以下命令
"git submodule add http://github.com/tpope/vim-fugitive.git bundle/vim-fugitive
"git submodule add https://github.com/msanders/snipmate.vim.git bundle/snipmate
"git submodule add https://github.com/tpope/vim-surround.git bundle/vim-surround
"git submodule add https://github.com/tpope/vim-git.git bundle/vim-git
"git submodule add https://github.com/ervandew/supertab.git bundle/supertab
"git submodule add https://github.com/sontek/minibufexpl.vim.git bundle/minibufexpl
"git submodule add https://github.com/wincent/Command-T.git bundle/command-t
"git submodule add https://github.com/mitechie/pyflakes-pathogen.git bundle/pyflakes-pathogen
"git submodule add https://github.com/mileszs/ack.vim.git bundle/ack
"git submodule add https://github.com/sjl/gundo.vim.git bundle/gundo
"git submodule add https://github.com/fs111/pydoc.vim.git bundle/pydoc
"git submodule add https://github.com/fs111/pydoc.vim.git bundle/pydoc
"git submodule add https://github.com/fs111/pydoc.vim.git bundle/pydoc
"git submodule add https://github.com/vim-scripts/pep8.git bundle/pep8
"git submodule add https://github.com/alfredodeza/pytest.vim.git bundle/pytest
"git submodule add https://github.com/reinh/vim-makegreen bundle/vim-makegreen
"git submodule add https://github.com/vim-scripts/TaskList.vim.git bundle/tasklist
"git submodule add https://github.com/vim-scripts/The-NERD-tree.git bundle/the-nerd-tree
"git submodule add https://github.com/sontek/rope-vim.git bundle/rope-vim
"git submodule init  进入某插件目录更新一个插件
"git submodule update
"git submodule foreach git submodule init   再.vim路径下，更新所有插件
"git submodule foreach git submodule update
"NOTE：在安装的过程中，minibufexpl.vim.git和rope-vim.git没有安装成功，需要用户名和密码。
"现在，我们已经将vim配置放到了git仓库中。执行完上面的操作后，在.vim目录下会生成一个隐藏文件：.gitmodules。
"UPDATED(20141020):
"添加了这些插件作为submodule后，这些插件中会产生一些untracked文件（比如bundle/snipmate/doc/tags 文件）。在.gitignore中过滤是不起作用的。
"解决方法是（【9】是stackoverflow中所提问题，【10】是解决方案的出处）：
"By adding the ignore = dirty option to each one of the entries in the .gitmodules file.
"[submodule "zen-coding-gedit3"]
"path = zen-coding-gedit3
"url = git://github.com/leafac/zen-coding-gedit3.git
"ignore = dirty

"4. 将其提交到GitHub
"由于.vimrc 文件不在.vim目录下，所以将其从~目录copy到.vim目录，然后add。（Please use method in UPDATED2）
"git status
"git commit -m "add .vim plugins"
"cp ~/.vimrc .
"git add .vimrc
"git status
"git commit -m "add .vimrc file"
"git status
"git remote add origin https://github.com/zhchnchn/VimConfig.git
"git push -u origin master
"如果错了，需要删除
"git rm  --cached bundle/fugitive                          //file
"git rm  —cached -r xxx                                    //dir
"UPDATED（20141020）：
"git push -u origin master：Push到远程仓库，同时设置跟踪分支，下次push的时候，直接输入git push即可，系统会自动用本地master分支跟踪远程master分支 。
"UPDATED2（20141020）
"为了将所有的文件都置于版本控制下，我们需要将~/.vimrc 移到~/.vim下（有gvimrc的话，将其一并移动），为了让他不再是一个隐藏文件，我们去掉了前面的点(.)【11】。
"mv ~/.vimrc ~/.vim/vimrc
"mv ~/.gvimrc ~/.vim/gvimrc
"当启动vim时，仍然会试图寻找~下的.vimrc文件，所以我们创建一个symbolic link。将~/.vim/vimrc文件link 到 ~/.vimrc文件。
"ln -s ~/.vim/vimrc ~/.vimrc
"ln -s ~/.vim/gvimrc ~/.gvimrc
"将以上修改commit到github。

"5. 如何将vim插件同步到别的机器上
"将.vim配置提交到Github之后，如何同步到别的机器上使用呢？
"NOTE：下面所涉及的“本地”都是指别的机器的“本地”目录。
"（1）将.vim配置clone到别的机器的～/.vim目录下（如果没有.vim则新建一个）
"git clone git@github.com:zhchnchn/VimConfig.git ~/.vim
"（2）创建symbolic link，将~/.vim/vimrc文件link 到 ~/.vimrc文件。
"ln -s ~/.vim/vimrc ~/.vimrc
"（3）如果修改了本地的vimrc文件，在 git add和git commit之后，可以直接git push提交到github上。
"（4）查看clone到本地的bundle目录下的各个插件目录，发现它们都是空的，那是因为还没同步到本地来。将他们同步到本地【11】：
"~/.vim$ git submodule init
"~/.vim$ git submodule update
"下次更新同步的话（不是重装）
"~/.vim$ git pull
"~/.vim$ git submodule init
"~/.vim$ git submodule update
"前一条命令作用是“registers the submodule”。
"后一条的作用是“Checks out the version of each plugin's repository which was committed to the .vim repository before”.，它会将各个插件下载到本地。

"6. 如何在pathogen下安装主题风格插件呢？
"pathogen 无法安装配色主题风格，因为它会将所有插件都安装在bundle目录下，而vim只认~/.vim/colors/下的主题风格。因此只能将主题插件手工放置于 ~/.vim/colors/下【14】。
"比如要安装下面的2个主题插件，需要将下载的插件中的 *.vim 文件（即solarized.vim、molokai.vim文件，而非包含*.vim 文件的目录）拷贝至 ~/.vim/colors/目录下（如果没有则手动创建）。
"solarized（https://github.com/altercation/vim-colors-solarized ）
"molokai（https://github.com/tomasr/molokai ）
"然后在 .vimrc文件中设定主题：
"" 配色方案
"set background=dark
"colorscheme solarized
""colorscheme molokai

"Refer
"【1】Turning Vim into a modern Python IDE（http://www.sontek.net/blog/2011/05/07/turning_vim_into_a_modern_python_ide.html）
"【2】Turning Vim into a modern Python IDE（中译文，其中有好多错误，请对照引文参考。http://python.42qu.com/11180003）
"【3】教程：使用 pathogen + git 管理 Vim 插件（http://lostjs.com/2012/02/04/use-pathogen-and-git-to-manage-vimfiles/）
"【4】Ubuntu12.04安装Git（http://www.cnblogs.com/zhcncn/p/4030078.html）
"【5】vim-pathogen（https://github.com/tpope/vim-pathogen）
"【6】Git Submodule使用完整教程（http://www.kafeitu.me/git/2012/03/27/git-submodule.html）
"【7】Resolving a vim plugin mapping conflict - mapping already exists for \t (http://stackoverflow.com/questions/18346350/resolving-a-vim-plugin-mapping-conflict-mapping-already-exists-for-t)
"【8】Pathogen does not load plugins(http://stackoverflow.com/questions/3383502/pathogen-does-not-load-plugins/6365667)
"【9】How to get rid of git submodules untracked status?（http://stackoverflow.com/questions/5126765/how-to-get-rid-of-git-submodules-untracked-status）
"【10】How to ignore changes in git submodules（http://www.nils-haldenwang.de/frameworks-and-tools/git/how-to-ignore-changes-in-git-submodules）
"【11】Synchronizing plugins with git submodules and pathogen （http://vimcasts.org/transcripts/27/en/）
"【12】A Brief Note On Pathogen For Vim（http://blog.darevay.com/2010/10/a-brief-note-on-pathogen-for-vim/）
"【13】https://github.com/gmarik/Vundle.vim/issues/176
"【14】所需即所获：像 IDE 一样使用 vim（https://github.com/yangyangwithgnu/use_vim_as_ide）
"本文永久更新地址：http://www.linuxdiyf.com/linux/18110.html

"install_name_tool -change  old new MacVim
"otool -L 查看
"解决打开后python问题
"Fatal Python error: PyThreadState_Get: no current thread的问题
"cd /opt/local/Library/Frameworks;
"mv sudo mv Python.framework x
"是因为macvim与YCM所使用python版本对不上号。
"经常会遇到这个问题，是因为mac里可能会有多个python版本，比如brew来一个，系统默认一个，xcode再来一个，最暴力的办法，只认一个，剩下的都ln -s过来。
"标准c语法支持
"这步不是必须的，c开发的话最好有。因为mac下的libc似乎版本很奇怪。
"先去llvm.org上下载对应平台的二进制包，解压到~/ycm_temp，里面有bin\lib\include等目录。
"cd~
"mkdir ycm_build
"cd ycm_build
"cmake -G "Unix Makefiles" -DPATH_TO_LLVM_ROOT=~/ycm_temp . ~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp
"生成makefile文件后，执行
"make ycm_support_libs
"完工！
"细节配置项
"vim ~/.vimrc 添加两行
"let g:ycm_confirm_extra_conf = 0
"let g:syntastic_always_populate_loc_list = 1
"第一行的意思是导入ycm配置不再需要手动确认。
"vim ~/.ycm_extra_conf.py 在对应的位置，flags中，添加两行：
"'-isystem',
"'/Users/chenzhen/ycm_temp/lib',
"'-isystem',
"'/Users/chenzhen/ycm_temp/include',
"改成自己电脑的目录。使用llvm的库。
"这里-isystem一般是写第三方库的，有warning也不会显示，-I一般写自己的代码目录，有warning还是要显示的。
"最好是在~/.ycm_extra_conf.py中定义好全局的，每个项目下放一个自己的。
"快捷键
"ctrl+I前进,ctrl+O后退。
"给~/.vimrc添加内容：
"let g:ycm_error_symbol = '>>'
"let g:ycm_warning_symbol = '>*'
"nnoremap gl :YcmCompleter GoToDeclaration<CR>
"nnoremap gf :YcmCompleter GoToDefinition<CR>
"nnoremap gg :YcmCompleter GoToDefinitionElseDeclaration<CR>
"nmap <F4> :YcmDiags<CR>
"能得到： * >>表示行有错误 * >*表示行有警告 * gl gf gg就是找代码定义声明 * f4是打开编译窗口(fn+F4)
"让配色cool一点
"vim ~/.vimrc
"添加内容：
"Plugin 'zenorocha/dracula-theme', {'rtp': 'vim/'}
"打开macvim，运行:PluginInstall。
"再vim ~/.vimrc
"添加内容：
"syntax on
"color Dracula
"添加代码片断助手
"vim ~/.vimrc
"Plugin 'SirVer/ultisnips'
"Plugin 'honza/vim-snippets'
"let g:UltiSnipsExpandTrigger="<D-k>"
"let g:UltiSnipsEditSplit="vertical"
"重新mvim进行运行:PluginInstall。关于代码片断功能，见https://github.com/SirVer/ultisnips%E3%80%82
"command+k自动完成代码片断。比如写一个APACHE选中，按command+k自动就完成一片。
"bbox command+k: 写一个大注释框框。
"datetime command+k: 当前的时间。
"如果出现打开nginx.c不能使用上c.snips里的定义，请确保.vimrc里的一行叫filetype plugin indent on的显示在所有plugin最后。

"编译完成后,运行vim结果出错.
"$ vim
"Vim: Caught deadly signal ABRT
"Vim: Finished.
"Abort trap: 6
"查了一圈发现,加一个参数后能正常工作
"$ DYLD_FORCE_FLAT_NAMESPACE=1 vim
"但毕竟这不是一个办法,最后在github上的issue页面上看到问题的解决办法:
"brew unlink python
"运行后依然无效!!!!崩溃!!!
"然后继续看下去
"$ otool -L /usr/local/Cellar/macvim/7.4-73_1/MacVim.app/Contents/MacOS/Vim | grep -i python
"    /System/Library/Frameworks/Python.framework/Versions/2.7/Python (compatibility version 2.7.0, current version 2.7.6)
"而我的系统上默认的python是2.7.9,而且路径为/Library/Frameworks/Python.framework/Versions/2.7/python!
"OK找到问题所在了,现在的任务就是需要把这两个Python的版本调整成为一致!!!!
"HOW to do it? Google之找到办法,把所有的操作整理到一起给大家:
"复制代码
"sudo rm -R /System/Library/Frameworks/Python.framework/Versions/2.7
"sudo mv /Library/Frameworks/Python.framework/Versions/2.7 /System/Library/Frameworks/Python.framework/Versions
"sudo chown -R root:wheel /System/Library/Frameworks/Python.framework/Versions/2.7
"sudo rm /System/Library/Frameworks/Python.framework/Versions/Current
"sudo ln -s /System/Library/Frameworks/Python.framework/Versions/2.7 /System/Library/Frameworks/Python.framework/Versions/Current
"sudo rm /usr/bin/pydoc
"sudo rm /usr/bin/python
"sudo rm /usr/bin/pythonw
"sudo rm /usr/bin/python-config
"sudo ln -s /System/Library/Frameworks/Python.framework/Versions/2.7/bin/pydoc /usr/bin/pydoc
"sudo ln -s /System/Library/Frameworks/Python.framework/Versions/2.7/bin/python /usr/bin/python
"sudo ln -s /System/Library/Frameworks/Python.framework/Versions/2.7/bin/pythonw /usr/bin/pythonw
"sudo ln -s /System/Library/Frameworks/Python.framework/Versions/2.7/bin/python-config /usr/bin/python-config
"复制代码
"需要详细解释的童鞋,可以查看这篇文档.
"https://wolfpaulus.com/journal/mac/installing_python_osx/
"执行这段shell之后,需要编辑~/.bash_profile将系统默认的Python路径指向/System/Library这个文件夹
"# Setting PATH for Python 2.7
"# The orginal version is saved in .bash_profile.pysave
"PATH="/System/Library/Frameworks/Python.framework/Versions/2.7/bin:${PATH}"
"export PATH
"改变Python版本后,执行vim就不再出现段错误了.






