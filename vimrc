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
"    defaults write org.vim.MacVim MMNativeFullScreen 0
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

" map fuzzyfinder (CtrlP) plugin
" nmap <silent> <leader>t :CtrlP<cr>
"nmap <silent> <leader>r :CtrlPBuffer<cr>
"let g:ctrlp_map='<leader>t'
"let g:ctrlp_dotfiles=1
"let g:ctrlp_working_path_mode = 'ra'
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
" 开启保存 undo 历史功能
set undofile
" undo 历史保存路径 需要自己创建
set undodir=~/.undo_history/
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
"===================================================================================================
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
"===================================================================================================
"sudo git submodule add https://github.com/easymotion/vim-easymotion.git bundle/vim-easymotion
"easymotion 只做一件事：把满足条件的位置用 [A~Za~z] 间的标签字符标出来，找到你想去的位置再键入对应标签字符即可快速到达。比如，上面的例子，假设光标在行首，我只需键入 <leader><leader>fa （为避免与其他快捷键冲突，easymotion 采用两次 <leader> 作为前缀键），所有的字符 a 都被重新标记成 a、b、c、d、e、f 等等标签（原始内容不会改变），f 标签为希望移动去的位置，随即键入 f 即可到达。
"===================================================================================================
"==================================================minibufexpl.vim=================================================
"sudo git submodule add https://github.com/fholgado/minibufexpl.vim.git bundle/minibufexpl.vim
let g:miniBufExplorerAutoStart = 1
let g:miniBufExplBuffersNeeded = 1
let g:miniBufExplUseSingleClick = 1
"===================================================================================================
"==============================================ctrlsf.vim=====================================================
"ctrlsf.vim 后端调用 ack，所以你得提前自行安装。ctrlsf.vim 支持 ack 所有选项，要查找某个关键字（如，yangyang），你可以想让光标定位在该关键字上面，然后命令模式下键入

":CtrlSF
"将自动提取光标所在关键字进行查找，你也可以指定 ack 的选项

":CtrlSF -i -C 1 [pattern] /my/path/
"为方便操作，我设定了快捷键：

" 使用 ctrlsf.vim 插件在工程内全局查找光标所在关键字，设置快捷键。快捷键速记法：search in project
nnoremap <Leader>sp :CtrlSF<CR>
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