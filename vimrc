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
set nocompatible              " be iMproved, required
" Enable filetype plugins
filetype plugin on
filetype indent on

" Set to auto read when a file is changed from the outside
set autoread

" With a map leader it's possible to do extra key combinations
" like <leader>w saves the current file
let mapleader = "'"
let g:mapleader = "'"

" Fast saving
nmap <leader>w :w!<cr>
set clipboard=unnamed
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
set backspace=eol,start,indent
set whichwrap+=<,>,h,l

" Ignore case when searching
set ignorecase

" When searching try to be smart about cases 
set smartcase

" Highlight search results
set hlsearch

" Makes search act like search in modern browsers
"set incsearch

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
"设置文件编码  
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1

"set termencoding=utf-8
"set guifont=Courier\ New\:h12
"set guifontwide=NSimsun\:h12

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
"incsearch(is) 
"使用鼠标
set mouse=a
"去掉输入错误的提示声音
set noeb
let Tlist_Ctags_Cmd="/usr/local/bin/ctags"
"ctags -R --c++-kinds=+p --fields=+iaS --extra=+q src
"map <c-F12> :!CTags -R --c++-kinds=+p --fields=+iaSl --extra=+q .<CR><CR>
map <C-F12> :!CTags -R --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+liaS --extra=+q --language-force=c++
map <F12> :!CTags -R --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+liaS --extra=+q --language-force=c++

"中文帮助和中文菜单
"if version >= 603
set helplang=cn
"set encoding=utf-8
"endif
"set encoding=utf-8
"set termencoding=utf-8

"操作：za，打开或关闭当前折叠；zM，关闭所有折叠；zR，打开所有折叠。
"基于缩进或语法进行代码折叠
""set foldmethod=indent
set foldmethod=syntax
"启动 vim 时关闭折叠代码
set nofoldenable
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Enable syntax highlighting
"difference between these two is that 'on' switch does search for first cpp file it find inside $VIMRUNTIME directory while enable switch searches in .vim directory too. more info about that
syntax enable
"syntax on
filetype on
"set background=dark
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
set nowritebackup

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
set softtabstop=4
set cc=100

" 显示tab和空格
"set list
" 设置tab和空格样式
"set lcs=tab:\|\ ,nbsp:%,trail:-
"ser lcs=tab:
" 设定行首tab为灰色
"highlight LeaderTab guifg=#666666
" 匹配行首tab
"match LeaderTab /^\t/

""""""""""""""""""""""""""""""
" => Status line
""""""""""""""""""""""""""""""
" Always show the status line
set laststatus=2

" Format the status line
"set statusline=\ %{HasPaste()}%F%m%r%h\ %w\ \ CWD:\ %r%{getcwd()}%h\ \ \ Line:\ %l
set statusline=%h%w%r\ %f\ %m%=\ %B\ \|\ %{&ff}\ \|\ %{&fenc!=''?&fenc:&enc}\ \|\ %{&ft!=''?&ft:'none'}\ \|\ %{&tabstop}\ %8(%l,%v%)\ %10(%p%%,%P%)
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

" 获取当前路径，将$HOME转化为~
function! CurDir()
    let curdir = substitute(getcwd(), $HOME, "~", "g")
    return curdir
endfunction
"set statusline=[%n]\ %f%m%r%h\ \|\ \ pwd:\ %{CurDir()}\ \ \|%=\|\ %l,%c\ %p%%\ \|\ ascii=%b,hex=%b%{((&fenc==\"\")?\"\":\"\ \|\ \".&fenc)}\ \|\ %{$USER}\ @\ %{hostname()}\ 

function! AutoLoadCTagsAndCScope()
    let max = 10
    let dir = './'
    let i = 0
    let break = 0
    while isdirectory(dir) && i < max
        if filereadable(dir . 'GTAGS')
            execute 'cs add ' . dir . 'GTAGS ' . glob("`pwd`")
            let break = 1
        endif
        if filereadable(dir . 'cscope.out')
            execute 'cs add ' . dir . 'cscope.out'
            let break = 1
        endif
        if filereadable(dir . 'tags')
            execute 'set tags +=' . dir . 'tags'
            let break = 1
        endif
        if break == 1
            execute 'lcd ' . dir
            break
        endif
        let dir = dir . '../'
        let i = i + 1
    endwhile
endf
nmap <F10> :call AutoLoadCTagsAndCScope()<CR>
" call AutoLoadCTagsAndCScope()
" http://vifix.cn/blog/vim-auto-load-ctags-and-cscope.html

"function(Vundle){
    "Vundle.vim插件管理配置
    "set nocompatible              " be iMproved, required
    "filetype off                  " required

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
	"filetype plugin indent on    " required
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
"}
"function(pathogen){
    "pathogen.vim插件管理配置
    execute pathogen#infect()
    "syntax on
    syntax enable
    filetype plugin indent on
"}
"function(CtrlP){
    let g:ctrlp_map = '<c-p>'
    let g:ctrlp_cmd = 'CtrlP'
    "修改该选项为1，设置默认为按文件名搜索（否则为全路径
    let g:ctrlp_by_filename = 1
    " 不限制CtrlP搜索文件的个数，默认为8000个好像
    let g:ctrlp_max_files=0
    "在提示符面板内可以使用 <c-d> 来切换。
    let g:ctrlp_working_path_mode = 'ac'
    map <Leader>p :CtrlP ./<cr>
    "map <c-m> :CtrlPMixed<cr>
    "map <c-b> :CtrlPBuffer<cr>
    let g:ctrlp_open_new_file = 'r'
    let g:ctrlp_clear_cache_on_exit = 0
    let g:ctrlp_match_window = 'bottom,order:btt,min:1,max:100,results:100'
    set wildignore+=*/.git/*,*/.hg/*,*/.svn/*
     let g:ctrlp_custom_ignore = {
        \ 'file': '\v(\.svn-base|\.o.d|\.so|\.o)@<!$'
        \ }
    let g:ctrlp_follow_symlinks=1
    let g:ctrlp_match_window_bottom=1
    let g:ctrlp_max_height=10
    let g:ctrlp_match_window_reversed=0
    let g:ctrlp_mruf_max=500
    let g:ctrlp_match_window_reversed=0
    let g:ctrlp_mruf_max=500
    let g:ctrlp_max_height = 10

    "let g:ctrlp_custom_ignore = 'node_modules\|^\.DS_Store\|^\.git\|^\.coffee|^\.svn-base|^\.swp'

    "let g:ctrlp_user_command = 'find %s -type f'        " MacOSX/Linux
"}
"function(Tagbar){
    nmap <F9> :TagbarToggle<CR>
    let g:tagbar_ctags_bin='ctags'
    " 启动时自动focus
    let g:tagbar_autofocus = 1
    autocmd VimEnter * nested :call tagbar#autoopen(1)  "automate to open tagbar
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
"}
"function(NerdTree){
    autocmd vimenter * NERDTree
    let g:NERDTreeQuitOnOpen=0
    " show hidden files in NERDTree
    let NERDTreeShowHidden=1
    " Toggle NERDTree
    nmap <F8> :NERDTreeToggle<CR>
    " expand to the path of the file in the current buffer
    "nmap <silent> <leader>y :NERDTreeFind<cr>



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
"}
"function(AirLine){
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
    set guifont=Meslo_LG_M_DZ_Regular_for_Powerline:h11
    let g:airline_powerline_fonts = 1
    "let g:Powerline_symbols="fancy"
    set encoding=utf-8
    "set ttimeoutlen=50
    set laststatus=2
    "set t_Co=256
    "打开tabline
    "let g:airline#extensions#tabline#enabled = 1
    set guifont=Meslo_LG_M_DZ_Regular_for_Powerline:h11
    let g:airline_powerline_fonts = 1
    "let g:airline_theme='solarized dark'
    "以下会导致黑屏一下
    "if has('gui_running')
    "  let g:airline_theme='solarized dark'
    "else
    "  let g:airline_theme='molokai'
    "endif

    let g:CtrlSpaceStatuslineFunction = "airline#extensions#ctrlspace#statusline()"
"}
"function(BufferLine){
    "" 开启tabline
    let g:airline#extensions#bufferline#enabled = 1


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
"}
"function(syntastic){
    set statusline+=%#warningmsg#
    set statusline+=%{SyntasticStatuslineFlag()}
    set statusline+=%*
    let g:syntastic_always_populate_loc_list = 1
    let g:syntastic_auto_loc_list = 1
	let g:syntastic_check_on_open = 0
	let g:syntastic_check_on_wq = 1
    let g:syntastic_ignore_files=[".*\.py$"]
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
    let g:syntastic_shell = "/bin/zsh"
"}
"function(undoTree){
    if has("persistent_undo")
       set undodir=~/.undodir/
       set undofile
    endif
    nnoremap <F6> :UndotreeToggle<cr>
"}
"function(Ycm){
	"echo 1
    let g:ycm_confirm_extra_conf = 1
    "let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
    "let g:ycm_global_ycm_extra_conf = '/Users/BLUE/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
    let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
    let g:ycm_collect_identifiers_from_tags_files = 1
    let g:ycm_seed_identifiers_with_syntax = 1
    "set tags+=~/work/test/ctest/UPlayer_Refactoring_Tudou/tags
    set tags+=./../tags,./../../tags,./../../../tags

	let cwd = getcwd()
    let tagfilename = cwd . "/tags"
    "echo tagfilename
    set tags+=tagfilename
    set tags+=$PWD/tags
    "set tags+=~/work/UPlayer/branches/UPlayer_Android/UPlayer_Meizu_4.6.1/tags
    "let cmd = 'ctags -a -f ' . tagfilename . ' --c++-kinds=+p --fields=+iaS --extra=+q ' . '"' . f . '"'
    "call DelTagOfFile(f)
    "let resp = system(cmd)

	"set tags+=getcwd()/tags
    let g:ycm_confirm_extra_conf = 0
    let g:ycm_server_keep_logfiles = 1
    let g:ycm_server_log_level = 'debug'

    set completeopt=longest,menu    "让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
    autocmd InsertLeave * if pumvisible() == 0|pclose|endif "离开插入模式后自动关闭预览窗口
    inoremap <expr> <CR>       pumvisible() ? "\<C-y>" : "\<CR>"    "回车即选中当前项
    nnoremap <leader>gl :YcmCompleter GoToDeclaration<CR>
    nnoremap <leader>gf :YcmCompleter GoToDefinition<CR>
    nnoremap <leader>gg :YcmCompleter GoToDefinitionElseDeclaration<CR>
    nmap <F4> :YcmDiags<CR>
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
    "静态检查
    let g:ycm_show_diagnostics_ui = 0

    let g:ycm_use_ultisnips_completer = 1

    " YCM 集成 OmniCppComplete 补全引擎，设置其快捷键
    inoremap <leader>; <C-x><C-o>
    " 补全内容不以分割子窗口形式出现，只显示补全列表
    set completeopt-=preview

    " 设置在下面几种格式的文件上屏蔽ycm
    let g:ycm_filetype_blacklist = {
          \ 'tagbar' : 1,
          \ 'nerdtree' : 1,
          \}
    "youcompleteme  默认tab  s-tab 和 ultisnips 冲突
    "let g:ycm_key_list_select_completion = ['<Down>']
    "let g:ycm_key_list_previous_completion = ['<Up>']
    "let g:ycm_key_list_previous_completion = ['<M-tab>']
    " 修改对C函数的补全快捷键，默认是CTRL + space，修改为ALT + ;
    let g:ycm_key_invoke_completion = "<Leader><Space>"

    let g:UltiSnipsExpandTrigger="<leader><tab>"
    let g:UltiSnipsJumpForwardTrigger="<leader><tab>"                           
    let g:UltiSnipsJumpBackwardTrigger="<leader><M-tab>"




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
"}
"function(ultisnips){
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
"}
"function(EasyAlign){
    " Start interactive EasyAlign in visual mode (e.g. vipga)
    xmap ga <Plug>(EasyAlign)

    " Start interactive EasyAlign for a motion/text object (e.g. gaip)
    nmap ga <Plug>(EasyAlign)
"}
"function(AG){
    let g:ag_prg="ag --vimgrep --smart-case  --ignore tags"
    let g:ag_highlight=1
    let g:ag_format="%f:%l:%m"
    map <leader>ag :Ag!<cr>
"}
"function(vimshell){
    "let g:vimshell_user_prompt = 'fnamemodify(getcwd(), ":~")'
    "used VimShellPop open windows
    "    "let g:vimshell_right_prompt = 'vcs#info("(%s)-[%b]", "(%s)-[%b|%a]")'
        
    "    if has('win32') || has('win64')
    "      " Display user name on Windows.
    "      let g:vimshell_prompt = $USERNAME."% "
    "    else
    "      " Display user name on Linux.
    "      let g:vimshell_prompt = $USER."% "
    "    endif
    let g:vimshell_environment_term = 'zsh'
    let g:vimshell_scrollback_limit = 100000
    let g:vimshell_prompt = '% '
    "let g:vimshell_user_prompt = 'fnamemodify(getcwd(), ":~") . " " .' .
    "\                            'vimshell#vcs#info("(%s)-[%b]", "(%s)-[%b|%a]")'
    let g:vimshell_ignore_case = 1
    let g:vimshell_smart_case = 1
    map <Leader>vs :VimShellPop<CR>
    "map <Leader>vs :VimShell -split<CR>
    "map <Leader>vsc :VimShellClose<CR>
"}

"function(indent_guides){
    " 随 vim 自启动
	let g:indent_guides_enable_on_vim_startup=0
    " 从第二层开始可视化显示缩进
    let g:indent_guides_start_level = 2
    " 色块宽度
    let g:indent_guides_guide_size = 1
    " 快捷键 i 开/关缩进可视化
    let g:indent_guides_soft_pattern = ' '
    :nmap <silent> <Leader>ig <Plug>IndentGuidesToggle

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
"}
"function(a.vim){
    " *.cpp 和 *.h 间切换
    nmap <Leader>ch :A<CR>
    " 子窗口中显示 *.cpp 或 *.h
    nmap <Leader>sch :AS<CR>
    "这样，键入 ;ch 就能在实现文件和接口文件间切换，键入 ;sch 子窗口中将显示实现文件/接口文件。
"}

"function(vimprj){
    "indexer依赖
"}
"function(DfrankUtil){
    "indexer依赖
"}

"function(indexer){
    let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"
"}
"function(NERD_commenter){
    " plugin - NERD_commenter.vim   注释代码用的，

    " [count],cc 光标以下count行逐行添加注释(7,cc)

    " [count],cu 光标以下count行逐行取消注释(7,cu)

    " [count],cm 光标以下count行尝试添加块注释(7,cm)

    " ,cA 在行尾插入 /* */,并且进入插入模式。 这个命令方便写注释。

    " 注：count参数可选，无则默认为选中行或当前行

    "-----------------------------------------------------------------

    let NERDSpaceDelims=1       " 让注释符与语句之间留一个空格

    let NERDCompactSexyComs=1   " 多行注释时样子更好看
"}
"function(protodef){
    "sudo git submodule add https://github.com/derekwyatt/vim-protodef.git bundle/vim-protodef.vim
    " 设置 pullproto.pl 脚本路径
    let g:protodefprotogetter='~/.vim/bundle/vim-protodef.vim/pullproto.pl'
     " 成员函数的实现顺序与声明顺序一致
    let g:disable_protodef_sorting=1
    "MyClass.cpp 中我键入 protodef 定义的快捷键 <leader>PP，自动生成了函数框架。
"}
"function(easymotion){
    "sudo git submodule add https://github.com/easymotion/vim-easymotion.git bundle/vim-easymotion
    "easymotion 只做一件事：把满足条件的位置用 [A~Za~z] 间的标签字符标出来，找到你想去的位置再键入对应标签字符即可快速到达。比如，上面的例子，假设光标在行首，我只需键入 <leader><leader>fa （为避免与其他快捷键冲突，easymotion 采用两次 <leader> 作为前缀键），所有的字符 a 都被重新标记成 a、b、c、d、e、f 等等标签（原始内容不会改变），f 标签为希望移动去的位置，随即键入 f 即可到达。
    let g:EasyMotion_leader_key = '<Leader><Leader>'
"}
"function(miniBufExplorer){
    let g:miniBufExplorerAutoStart = 0
    let g:miniBufExplBuffersNeeded = 0
    let g:miniBufExplUseSingleClick = 0
"}
"function(CtrlSF){
    " 使用 ctrlsf.vim 插件在工程内全局查找光标所在关键字，设置快捷键。快捷键速记法：search in project ctrlsf插件依赖于ack支持，因此还需要先装一下ack
    nnoremap <Leader>sp :CtrlSF<CR>

    let g:ctrlsf_auto_close = 0
"}
"function(YankRing){
    "sudo git submodule add https://github.com/vim-scripts/YankRing.vim.git bundle/YankRing.vim
    "在vim裡面，copy只有一次的歷史紀錄， 
    "如果希望能夠保留copy的歷史紀錄，就可以用這個plugin

    "這個plugin也提供了非常好用「歷史替代」的功能。

    "把這個plugin裝好之後，試試多copy幾段文字， 
    "然後在normal mode按p貼上，然後再按<c-p>或<c-n>， 
    "就會把剛才貼上的文字替換再前一次歷史的文字。
    "非常好用，強力推薦。
"}
"function(BufExplorer){
    map <leader>b :BufExplorer<cr>
    let g:bufExplorerDefaultHelp=0
    let g:bufExplorerDetailedHelp=0
    let g:bufExplorerFindActive=1 
    let g:bufExplorerShowDirectories=1
    let g:bufExplorerShowNoName=1
    let g:bufExplorerShowRelativePath=1
    let g:bufExplorerSortBy='name'
"}
"function(MRU){
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
"}
"function(Vundle插件管理){
	let g:multi_cursor_use_default_mapping=0
	" Default mapping
	let g:multi_cursor_next_key='<C-m>'
	let g:multi_cursor_prev_key='<C-p>'
	let g:multi_cursor_skip_key='<C-x>'
	let g:multi_cursor_quit_key='<Esc>'
"}
"function(Unite){
    "ctrl f ctrl b 本来是翻页
    "空格选中 再a，进action
    "nnoremap <C-f> :Unite -start-insert file<CR>
    "nnoremap <C-b> :Unite buffer<CR>
    "nnoremap <Leader>ff :Unite file<CR>
    "let g:unite_data_directory='~/.vim/.cache/unite'
    "nnoremap <leader>f :Unite -start-insert file<CR>
    let g:unite_enable_start_insert=1
    let g:unite_source_history_yank_enable=1
    let g:unite_source_rec_max_cache_files=5000
    if executable('ag')
      let g:unite_source_grep_command='ag'
      let g:unite_source_grep_default_opts='--nocolor --nogroup -S -C4'
      let g:unite_source_grep_recursive_opt=''
    elseif executable('ack')
      let g:unite_source_grep_command='ack'
      let g:unite_source_grep_default_opts='--no-heading --no-color -C4'
      let g:unite_source_grep_recursive_opt=''
    endif
    nnoremap <leader>f :Unite -start-insert file<CR>
    nmap <buffer> Q <plug>(unite_exit)
"}
"function(signify){
    let g:signify_vcs_list              = [ 'git', 'hg' ,'svn']
    let g:signify_cursorhold_insert     = 1
    let g:signify_cursorhold_normal     = 1
    let g:signify_update_on_bufenter    = 0
    let g:signify_update_on_focusgained = 1
    nnoremap <leader>gt SignifyToggle
    nnoremap <leader>gh SignifyToggleHighlight
    nnoremap <leader>gr SignifyRefresh
    nnoremap <leader>gd SignifyDebug
"}
"function(CtrlSpace){
    if has("gui_running")
        " Settings for MacVim and Inconsolata font
        let g:CtrlSpaceSymbols = { "File": "◯", "CTab": "▣", "Tabs": "▢" }
    endif
    if executable("ag")
        let g:CtrlSpaceGlobCommand = 'ag -l --nocolor -g ""'
    endif
    let g:CtrlSpaceSearchTiming = 500
    let g:airline_exclude_preview = 1
    let g:CtrlSpaceUseMouseAndArrowsInTerm = 0
    let g:CtrlSpaceUseTabline = 0
    let g:CtrlSpaceDefaultMappingKey = "<C-F1>"
    "let g:CtrlSpaceDefaultMappingKey = "<C-Space>"
"}
"function(DoxygenToolkit){
    "let g:DoxygenToolkit_briefTag_pre="@Synopsis  " 
    "let g:DoxygenToolkit_paramTag_pre="@Param " 
    "let g:DoxygenToolkit_returnTag="@Returns   " 
    "let g:DoxygenToolkit_blockHeader="--------------------------------------------------------------------------" 
    "let g:DoxygenToolkit_blockFooter="----------------------------------------------------------------------------" 
    "let g:DoxygenToolkit_authorName="BLUE" 
    "let g:DoxygenToolkit_licenseTag="1.0.1"   "<-- !!! Does not end with "\<enter>"

	"map <Leader>dl :DoxLic<CR>
	"map <Leader>da :DoxAuthor<CR>
	"map <Leader>dx :Dox<CR>
	"-----------------------------------------------------------------

	" plugin - DoxygenToolkit.vim  由注释生成文档，并且能够快速生成函数标准注释

	"-----------------------------------------------------------------

	let g:DoxygenToolkit_authorName="LC"
	let g:DoxygenToolkit_briefTag_funcName="yes"

	let g:DoxygenToolkit_briefTag_pre="@Synopsis  " 
	let g:DoxygenToolkit_paramTag_pre="@Param " 
	let g:DoxygenToolkit_returnTag="@Returns   " 
	"Dox 命令后，上线添加两条线
	let g:DoxygenToolkit_blockHeader="----------------------------------------------------------------------------" 
	let g:DoxygenToolkit_blockFooter="----------------------------------------------------------------------------" 
	"添加文件描述
	map <leader>xa :DoxAuthor<CR>
	"添加函数描述
	map <leader>xf :Dox<CR>

	map <leader>xb :DoxBlock<CR>
	map <leader>xc a/* <C-R>=strftime("%Y-%m-%d %a %I:%M %p")<CR> by lichen  */<LEFT><LEFT><LEFT>
	"map <leader>xc a /*  */<LEFT><LEFT><LEFT>
	"添加liscens信息
	map <Leader>xl :DoxLic<CR>
"}
"function(gundo){
    let g:gundo_disable = 1
    "let g:gundo_prefer_python3 = 1
    "nnoremap <F6> :GundoToggle<CR>
    "let g:gundo_width = 60
    "let g:gundo_preview_height = 40
    "let g:gundo_right = 1
    "{
     "   try
     "       " undo 历史保存路径 需要自己创建 mkdir -P ~/.vim_runtime/temp_dirs/undodir
     "       set undodir=~/.vim_runtime/temp_dirs/undodir
     "       " 开启保存 undo 历史功能
     "       set undofile
     "   catch
     "   endtry
    "}
"}

"function(tmux-navigator){
    
"}
"function(vim-surround){
    
"}

"function(vimproc){
    
"}

"function(AutoPairs){
	
	let g:AutoPairsFlyMode = 1
	let g:AutoPairsShortcutBackInsert = '<M-b>'
"}
"function(syntax高亮C++语法)
"{
	let g:cpp_class_scope_highlight = 1
	let g:cpp_experimental_template_highlight = 1
"}
"function(Mark-and-Highlight){
	"<F1>            Turn on/update highlighting for all lines with markers
	"<F2>            Turn off highlighting for lines with markers
	"<SHIFT-F2> Erase all markers [a-z]
	"<F5>             Add a mark on the current line (and highlight)
	"<SHIFT-F5> Remove the mark on the current line

	"Then, just jump from one mark to the next using the classic [' and ]' jumps
"}
"function(vim-ultimate-colorscheme-utility){
	let g:ulti_color_auto_save = 0
	let g:ulti_color_default_keys = 0
	let g:ulti_color_auto_load = 0
"}

"function(color-setting){
  let g:solarized_termcolors=256
  if has('gui_running')
    set fuoptions=maxvert,maxhorz
    au GUIEnter * set fullscreen

    "不要"set background=light
    "set background=dark
    "不要"let g:solarized_termcolors = 256  " +New line!!
    "colorscheme molokai
    "colorscheme solarized
    "以下另一种配色
    set background=dark
    colorscheme material-theme
    "colorscheme dracula
    "colorscheme vombatidae
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
    set background=dark
    "colorscheme molokai
    colorscheme dracula
    "colorscheme material-theme
    "light
    "hi IndentGuidesOdd  ctermbg=white
    "hi IndentGuidesEven ctermbg=lightgrey
    "dark
    "hi IndentGuidesOdd  ctermbg=black
    "hi IndentGuidesEven ctermbg=darkgrey
    "set nofu
  endif
    "set background=dark
    let g:solarized_termcolors=256
    set t_Co=256
    "colorscheme solarized
    "colorscheme molokai
    "colorscheme phd

    "colorscheme desert
    "set background=dark  
"}
"function(syntax-clolor-setting){
		"*Comment        v 任何注释
        "*Constant       v 任何常数
         "String         v 一个字符串常数: "这是一个字符串"
         "Character      v 一个字符常数: 'c'、'\n'
         "Number         v 一个数字常数: 234、0xff
         "Boolean        v 一个布尔型常数: TRUE、false
         "Float          v 一个浮点常数: 2.3e10

        "*Identifier     v 任何变量名
         "Function       v 函数名 (也包括: 类的方法名)

        "*Statement      v 任何语句
         "Conditional    v if、then、else、endif、switch 等
         "Repeat         v for、do、while、etc.
         "Label          v case、default 等
         "Operator       v "sizeof"、"+"、"*" 等
         "Keyword        v 任何其它关键字
         "Exception      v try、catch、throw

        "*PreProc        v 通用预处理命令
         "Include        v 预处理命令 #include
         "Define         v 预处理命令 #define
         "Macro          v 等同于 Define
         "PreCondit      v 预处理命令 #if、#else、#endif 等

        "*Type           v int、long、char 等
         "StorageClass   v static、register、volatile 等
         "Structure      v struct、union、enum 等
         "Typedef        v 一个 typedef

        "*Special        v 任何特殊符号
         "SpecialChar    v 常数中的特殊字符
         "Tag            v 这里可以使用 CTRL-]
         "Delimiter      v 需要注意的字符
         "SpecialComment v 注释里的特殊字符
         "Debug          v 调试语句

        "*Underlined     v 需要突出的文本，HTML 链接

        "*Ignore         v 留空，被隐藏

        "*Error          v 任何有错的构造

        "*Todo           v 任何需要特殊注意的部分；多是关键字 TODO FIXME 和 XXX

	" 快速重载.vimrc
	map <leader>s :source ~/.vimrc<cr>
	"if has('gui_running')
    "C3E88D "浅浅绿
    "5C7E8C "墨绿
    "F77669 "橙红
    "66D9DD "海蓝
    "FF79C6 "亮粉
    "8BD649 "绿色
    "82B1FF "蓝色
    "C792EA BD93F9 "紫色
        "===================================================
        highlight Constant guifg=#f77669 guibg=NONE gui=NONE ctermfg=203 cterm=NONE
        highlight Comment guifg=#5c7e8c guibg=NONE gui=NONE ctermfg=66 cterm=NONE
        highlight String guifg=#c3e88d guibg=NONE gui=NONE ctermfg=150 cterm=NONE
        highlight Character guifg=#c3e88d guibg=NONE gui=NONE ctermfg=150 cterm=NONE
        highlight Number guifg=#f77669 guibg=NONE gui=NONE ctermfg=203 cterm=NONE
        highlight Boolean guifg=#f77669 guibg=NONE gui=NONE ctermfg=203 cterm=NONE
        highlight Float guifg=#f77669 guibg=NONE gui=NONE ctermfg=203 cterm=NONE

        highlight Function guifg=#82b1ff guibg=NONE gui=NONE ctermfg=111 cterm=NONE
        highlight cAnsiFunction guifg=#82b1ff guibg=NONE gui=NONE ctermfg=111 cterm=NONE
        highlight Identifier guifg=#a886a1 guibg=NONE gui=NONE ctermfg=139 cterm=NONE
		"这需要再改
        highlight Todo guifg=#37474f guibg=NONE gui=inverse,bold,italic,underline ctermfg=238 cterm=inverse,bold,underline ctermfg=61 ctermbg=NONE cterm=inverse,bold
        highlight cTodo  guifg=#37474F   gui=inverse,bold,italic,underline guibg=NONE ctermfg=61 ctermbg=NONE cterm=inverse,bold "guibg=#263238  
        highlight cCustomClass     guifg=#F1E655 guibg=NONE gui=NONE ctermfg=185 cterm=NONE
        highlight Type guifg=#8bd649 guibg=NONE gui=NONE ctermfg=113 cterm=NONE

        "highlight Type  guifg=#8BD649 guibg=NONE gui=NONE
		"宏粉，关键紫
        "{
            "关键字
            highlight Repeat guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Label guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Conditional guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Operator guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Keyword guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Exception guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Statement guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight StorageClass guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Structure guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            highlight Typedef guifg=#c792ea guibg=NONE gui=NONE ctermfg=177 cterm=NONE
            "宏
            highlight PreProc guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Include          guifg=#FF79C6 guibg=NONE gui=NONE
            highlight Include guifg=#66d9dd guibg=NONE gui=NONE ctermfg=80 cterm=NONE
            highlight Define guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            highlight Macro guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            highlight PreCondit guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            highlight Delimiter guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE

            "highlight Special guifg=#80cbc4 guibg=NONE gui=NONE ctermfg=116 cterm=NONE
            "highlight SpecialChar guifg=#80cbc4 guibg=NONE gui=NONE ctermfg=116 cterm=NONE
        "}
        "宏紫，关键粉
        "{
            "关键字
            "highlight Repeat guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Label guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Conditional guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Operator guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Keyword guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Exception guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Statement guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight StorageClass guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Structure guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "highlight Typedef guifg=#ff79c6 guibg=NONE gui=NONE ctermfg=212 cterm=NONE
            "宏
            "highlight PreProc guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE
            "highlight Include guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE
            "highlight Define guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE
            "highlight Macro guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE
            "highlight PreCondit guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE
            "highlight Delimiter guifg=#bd93f9 guibg=NONE gui=NONE ctermfg=141 cterm=NONE

            "highlight Special guifg=#80cbc4 guibg=NONE gui=NONE ctermfg=116 cterm=NONE
            "highlight SpecialChar guifg=#80cbc4 guibg=NONE gui=NONE ctermfg=116 cterm=NON
            "}
    "else
    "endif
    "}
"function{ 自定义，仅包括GUI 将rgb.txt.拷贝到gui2term目录，sudo python3 gui2term.py dracula.vim new_vim.vim 运行sudo python3 gui2term.py dracula.vim new_vim.vim 
    "if has('gui_running')
    "highlight Constant  guifg=#F77669 guibg=NONE gui=NONE
    "highlight Comment  guifg=#5C7E8C guibg=NONE gui=NONE
    "highlight String  guifg=#C3E88D guibg=NONE gui=NONE
    "highlight Character  guifg=#C3E88D guibg=NONE gui=NONE
    "highlight Number  guifg=#F77669 guibg=NONE gui=NONE
    "highlight Boolean  guifg=#F77669 guibg=NONE gui=NONE
    "highlight Float  guifg=#F77669 guibg=NONE gui=NONE

    "highlight Function  guifg=#82B1FF guibg=NONE gui=NONE
    "highlight Identifier  guifg=#A886A1 guibg=NONE gui=NONE "gui=bold
    "highlight cAnsiFunction guifg=#82B1FF guibg=NONE gui=NONE
    "这需要再改
    "highlight Todo  guifg=#37474F   gui=inverse,bold,italic,underline"guibg=#263238 guibg=NONE
    "highlight cTodo  guifg=#37474F   gui=inverse,bold,italic,underline"guibg=#263238 guibg=NONE
    "highlight cCustomClass     guifg=#F1E655 guibg=NONE gui=NONE
    "highlight Type             guifg=#8BD649 guibg=NONE gui=NONE

    "highlight Type             guifg=#8BD649 guibg=NONE gui=NONE
    "宏粉，关键紫
    "{
        "关键字
        "highlight Repeat           guifg=#C792EA guibg=NONE gui=NONE
        "highlight Label            guifg=#C792EA guibg=NONE gui=NONE
        "highlight Conditional      guifg=#C792EA guibg=NONE gui=NONE
        "highlight Operator         guifg=#C792EA guibg=NONE gui=NONE
        "highlight Keyword          guifg=#C792EA guibg=NONE gui=NONE
        "highlight Exception        guifg=#C792EA guibg=NONE gui=NONE
        "highlight Statement        guifg=#C792EA guibg=NONE gui=NONE
        "highlight StorageClass     guifg=#C792EA guibg=NONE gui=NONE
        "highlight Structure        guifg=#C792EA guibg=NONE gui=NONE
        "highlight Typedef          guifg=#C792EA guibg=NONE gui=NONE
        "宏
        "highlight PreProc          guifg=#FF79C6 guibg=NONE gui=NONE
        ""highlight Include          guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Include          guifg=#66D9DD guibg=NONE gui=NONE
        "highlight Define           guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Macro            guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight PreCondit        guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Delimiter        guifg=#FF79C6 guibg=NONE gui=NONE

        ""highlight Special         guifg=#80CBC4 guibg=NONE gui=NONE
        ""highlight SpecialChar     guifg=#80CBC4 guibg=NONE gui=NONE
        "}

		"宏紫，关键粉
        "{
            "关键字
        "highlight Repeat guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Label guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Conditional guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Operator guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Keyword guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Exception guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Statement          guifg=#FF79C6 guibg=NONE gui=NONE 
        "highlight StorageClass         guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Structure          guifg=#FF79C6 guibg=NONE gui=NONE
        "highlight Typedef         guifg=#FF79C6 guibg=NONE gui=NONE
            "宏
        "highlight PreProc guifg=#BD93F9 guibg=NONE gui=NONE
        "highlight Include guifg=#BD93F9 guibg=NONE gui=NONE
        "highlight Define guifg=#BD93F9 guibg=NONE gui=NONE
        "highlight Macro guifg=#BD93F9 guibg=NONE gui=NONE
        "highlight PreCondit guifg=#BD93F9 guibg=NONE gui=NONE
        "highlight Delimiter guifg=#BD93F9 guibg=NONE gui=NONE

        ""highlight Special  guifg=#80CBC4 guibg=NONE gui=NONE
        ""highlight SpecialChar  guifg=#80CBC4 guibg=NONE gui=NONE
        "}
    "else
    "endif
"}









