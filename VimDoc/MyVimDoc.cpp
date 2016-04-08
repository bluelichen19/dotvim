"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Maintainer: 
"       Blueliche
"       //http://amix.dk - amix@amix.dk
"
" Version: 
"       5.0 - 29/05/12 15:43:36
"
" Blog_post: 
"       //http://amix.dk/blog/post/19691#The-ultimate-Vim-configuration-on-Github
"
" Awesome_version:
"       //Get this config, nice color schemes and lots of plugins!
"
"       //Install the awesome version from:
"
"           //https://github.com/amix/vimrc
"
" Syntax_highlighted:
"       //http://amix.dk/vim/vimrc.html
"
" Raw_version: 
"       //http://amix.dk/vim/vimrc.txt
" Sections:
"    -> 键盘映射
"    -> vim控制台命令
"    -> vim常用设置解释
"    -> vim常用命令 
"    -> vim cscope ctags
"    -> pathogen 插件 
"    -> CtrlP 插件 
"    -> Ycm 插件 
"    -> NERDTree 插件 
"    -> gundo 插件 
"    -> signature 插件
"    -> protodef 插件
"    -> easymotion 插件
"    -> CtrlSF 插件
"    -> YankRing 插件
"    -> bufexplorer 插件
"    -> NERD_commenter 插件
"    -> surround 插件
"    -> Ag 插件
"    -> Syntastic 插件
"    -> DoxygenToolkit 插件
"    -> unite 插件
"    -> Airline 插件
"    -> mark 插件 
"    -> vim-indent-guides 插件
"    -> submodule 地址 
"    -> tmux 命令 
"    -> iTerm2 配色方案 
"    -> zsh 
"    -> python相关 
"    ->  
"    ->  
"    ->  
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => 键盘映射
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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

自己边学习边记录的，可能对大家有帮助 

有五种映射存在 
- 用于普通模式: 输入命令时。 
- 用于可视模式: 可视区域高亮并输入命令时。 
- 用于操作符等待模式: 操作符等待中 ("d"，"y"，"c" 等等之后)。 
见下: |omap-info|。 
- 用于插入模式: 也用于替换模式。 
• 用于命令行模式: 输入 ":" 或 "/" 命令时。 

下表是map绑定中，对应的模式代号。现在先了解一下，等看完之后再回过头看这个模式代号就会明白了。 
字 符 模 式 ~ 
<Space> 普通、可视、选择和操作符等待 
n 普通 
v 可视和选择 
s 选择 
x 可视 
o 操作符等待 
! 插入和命令行 
i 插入 
l 插入、命令行和 Lang-Arg 模式的 ":lmap" 映射 
c 命令行 


我主要讲解一下“n(普通模式)”下的两个绑定命令，等看完之后就对应的明白别的模式下的命令了。 
适用于普通模式的映射命令主要有： 
1. :map 
[语法] :map {lhs} {rhs} |mapmode-nvo| *:map* 
1.1 作用模式： n、v、o （普通、可视和选择、操作符等待） 
1.2 命令格式： 
:map {lhs} {rhs} 
含义： 在:map作用的模式中把键系列 {lhs} 映射为 {rhs}，{rhs}可进行映射扫描，也就是可递归映射。 
1.3 举例： 
:map td :tabnew .<cr> 
含义：在其作用模式（普通、可视、操作符）下，输入td等价于输入 :tabnew . <cr>。而普通模式下输入:tabnew . <cr>就是打开当前目录 
如果再定义绑定 :map ts td，就是指在其作用模式下输入ts等价于td，也就是打开当前目录。不过如果没有特殊需要，一般不建议递归映射。 

2. :noremap 
:moremap和:map命令相对，作用模式和命令格式都相同，只不过不允许再对{rhs}进行映射扫描，也就是{lhs}定义后的映射就是{rhs}的键序列，不会再对{rhs}键序列重新解释扫描。它一般用于重定义一个命令，当然如果:map不需要递归映射的话，建议试用:noremap 
比如： 
:noremap ts td 
它的意思是在其作用模式下，输入ts就是输入td，但是和:map不同的是，此时td再不会做进一步扫描解释。虽然之前已经定义了td，但是不会对td再做扫描 

3. :unmap 
:unmap是对应取消:map绑定的｛lhs｝，作用模式相同，命令格式 :unmap {lhs}。 
例如： 
:unmap td 
就是取消在其作用模式中td的绑定，比如之前td被绑定为:tabnew .<cr>，此时此绑定消失。
4. :mapclear 
:mapclear时对应取消所有:map绑定的，慎用！ 

5. :nmap 
:nmap是:map的普通模式板，也就是说其绑定的键只作用于普通模式。 
例如： 
:nmap td :tabnew .<cr> 和 :map td :tabnew .<cr> 在普通模式下等效 
6. :nnoremap 
:nnorempa和:nmap的关系和:noremap和:map的关系一样，只是:nmap的非递归版 
7. :nunmap 
:nunmap和:nmap的关系和:unmap和:map的关系一样，取消:nmap的绑定。 
8. :nmapclear 
:nmapclear是对应取消所有:map绑定的，慎用！ 

看完以上，应该可以发现一个规律，前4个是一组，后4个时一组，后一组比前一组多一个n就是指只作用于普通模式。其中每组内*nore*是其对应的非递归版、*un*是取消绑定某个<lhs>绑定、clear后缀是取消所有绑定。发现了这个规律，再翻到前面的模式代号表，你大体可以猜到vmap、xmap、smap、omap是什么意思了吧，以及相对应的nore版本、un版本、clear版本。 

另外： 
{rhs} 之前可能显示一个特殊字符: 
* 表示它不可重映射 
& 表示仅脚本的局部映射可以被重映射 
@ 表示缓冲区的局部映射 

到这一步你可以轻松的长吸一口气，因为相关的命令已经都了解了，记不住没关系，可以随时:help map一下。不过别急，后面还有map更多的选项等着去攻克。 

键表 |key-notation| 
<k0> - <k9> 小键盘 0 到 9 *keypad-0* *keypad-9* 
<S-...> Shift＋键 *shift* *<S-* 
<C-...> Control＋键 *control* *ctrl* *<C-* 
<M-...> Alt＋键 或 meta＋键 *meta* *alt* *<M-* 
<A-...> 同 <m-...> *<A-* 
<t_xx> termcap 里的 "xx" 入口键 

特殊参数： 
1. <buffer> 
2. <silent> 
3. <special> 
4. <script> 
5. <expr> 
6. <unique> 
它们必须映射命令的后边，在其他任何参数的前面。 

<buffer>如果这些映射命令的第一个参数是<buffer>，映射将只局限于当前缓冲区（也就是你此时正编辑的文件）内。比如： 
:map <buffer> ,w /a<CR> 
它的意思时在当前缓冲区里定义键绑定，“,w”将在当前缓冲区里查找字符a。同样你可以在其他缓冲区里定义： 
:map <buffer> ,w /b<CR> 
比如我经常打开多个标签(:tabedit)，想要在各自标签里定义",w"键绑定，那么你只要在每个标签页里分别定义就可，其作用域也只在各自的标签里。同样要清除这些缓冲区的键绑定也要加上<buffer>参数，比如： 
:unmap <buffer> ,w 
:mapclear <buffer> 

<silent>是指执行键绑定时不在命令行上回显，比如： 
:map <silent> ,w /abcd<CR> 
你在输入,w查找abcd时，命令行上不会显示/abcd，如果没有<silent>参数就会显示出来 

<special>一般用于定义特殊键怕有副作用的场合。比如： 
:map <special> <F12> /Header<CR> 

<unique>一般用于定义新的键映射或者缩写命令的同时检查是否该键已经被映射，如果该映射或者缩写已经存在，则该命令会失败 

<expr>. 如果定义新映射的第一个参数是<expr>，那么参数会作为表达式来进行计算，结果使用实际使用的<rhs>，例如： 
:inoremap <expr> . InsertDot() 
这可以用来检查光标之前的文本并在一定条件下启动全能 (omni) 补全。 
一个例子： 
let counter = 0 
inoremap <expr> <C-L> ListItem() 
inoremap <expr> <C-R> ListReset() 

func ListItem() 
let g:counter += 1 
return g:counter . '. ' 
endfunc 

func ListReset() 
let g:counter = 0 
return '' 
endfunc 
在插入模式下，CTRL-L插入顺序的列表编号，并返回；CTRL-R复位列表编号到0，并返回空。 


<Leader>	mapleader 
mapleader变量对所有map映射命令起效，它的作用是将参数<leader>替换成mapleader变量的值，比如： 
:map <Leader>A oanother line<Esc> 
如果mapleader变量没有设置，则用默认的反斜杠代替，因此这个映射等效于： 
:map \A oanother line<Esc> 
意思时输入\A键时，在下一行输入another line并返回到普通模式。 
如果设置了mapleader变量，比如： 
let mapleader = "," 
那么就等效于： 
:map ,A oanother line<Esc> 

<LocalLeader>	maplocalleader 
<LocalLeader>和<Leader>类似，只不过它只作用于缓冲区。 
因此在设置mapleader和maplocalleader时最好区分开，不要出现冲突。 

大体上映射的主要部分已经都提到了，还有很多具体的映射相关的内容可以参见:help map
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => vim控制台命令
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
scriptnames 显示插件启动顺序
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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => vim常用设置解释 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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
"快捷键
"ctrl+I前进,ctrl+O后退。
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

配置vim
vim的配置我认为在于两个方面，一是vim本身提供的各种设置选项，通过写配置文件~/.vimrc来调整，二是安装插件，这个就看想象力了。两者相结合，vim登神。

注意事项
所有的命令都有两种设置生效的方法。比如你希望设置一下搜索的高亮匹配，首先你可以进入vim中，在normal模式下直接输入：

:set hlsearch
:让你进入命令行模式，后面的set hlsearch则是具体的命令。在命令行中做的设置可以立刻生效，但随着你退出vim该设置也就被废弃了。

如果你希望某些设置每次进入vim都能生效，则需要第二种方法：直接编写.vimrc文件，也就是你vim的配置文件。具体方式是，在home下面新建名为.vimrc的文件，把你需要的配置命令直接写进去。还以搜索高亮为例，你可以直接写：

set hlsearch
这里不需要:，只写想要的命令就行。这样，每次vim启动都会自动读取你的配置文件，并将里面的命令逐个运行一遍。

将所有配置都集中在一个文本文件里的好处是方便备份和转移，有了它随便给你一台装有vim的机器，只需要一个拷贝，就能立刻还原你熟悉的工作环境。另外人们也热衷于分享自己的配置文件，尤其是近年来github人气爆棚，很多开发者都将自己的配置文件（不仅仅是vim的）托管在上面，其中不乏一些大神级人物，只需要简单的搜索就能看到行内高人的配置文件，这听上去就很诱人。

但我不建议新手一上来就拿别人的配置做自己用，毕竟，那些所谓的配置、技巧，甚至花样繁多的插件都不过是锦上添花的东西，如果连其中最基本的命令的含义都搞不清楚，也不明白为什么要这么设置，贸然把别人上百行的配置文件拿过来除了让你更加的迷惑和沮丧以外，起不到任何正面的意义。

正确的做法是先去理解vim的设计哲学，熟悉最基本的操作，体会vim自身的强大。你作出的每一项设定都应该是实际需求驱动的，并应保持简单和明确。如此不断积累下来的配置文件才能真正为你所用，并发挥出应有的威力。

一些最基本的设置
第一次在终端里打开vim的经历我至今记忆犹新，虽然被传的神乎其神（当然是真的），可看着没有经过配置的vim犹如石器时代穿越过来的界面我还是满心的怀疑。

我想这和linux的设计哲学有关，一开始只把最基本的东西给你，摒弃一切干扰，留出最大的定制空间，老手们觉得事情本该如此，但对新人来说却是个不大不小的障碍。

下面的一些基本配置主要目的是让光秃秃的vim变得友好一些，此外几乎每个vim的用户都会做出这些配置，所以仔细的了解一下很有必要。

如果你还记得前面提到的每个命令都有两种生效的方式，我希望你在将这些命令写进配置文件之前能在vim中切实地感受以下它的作用，只需简单的动手效果就超过我的千言万语。

第一件事是解开vim身上的封印

set nocompatible
这条命令的意思是让vim不要和vi一个德行。vim本身是vi的增强版，默认情况下vim行为和vi保持一致，这意味着很多vim的强大特性是无效的，这条命令将释放出一个真正强大的vim出来。

set mouse=a
这样做使得鼠标操作在vim中生效，主要方便浏览和选取。实际上你对vim掌握的越熟练，就越会发现，鼠标才是制约你操作效率的最大问题，所以我建议从一开始就放弃鼠标，专注于vim强大的功能。这里之所以有这么一条，完全是因为刚接触vim时有鼠标在手能安心很多。

set scrolloff=3
scrolloff的意思是翻页时屏幕上下沿保留的部分，3表示三行，这么设置的结果是你在移动光标时还有三行到底的时候就开始翻动整个页面了。我这么说估计还是不清楚，所以你最好试一下，一看便知这是一个多么舒心的设定了。3行是个人比较喜欢的值，你也可以根据自己的喜好来改动。

set nobackup
set noswapfile
这两条加起来是要求vim不生成备份文件和临时文件。我的文档有其他的备份途径，不太操心丢失的问题，这里觉得烦就一关了事。

set backspace=indent,eol,start
vim默认情况下的回删行为相当不人性，遇到缩进或者在行首无效。这样设定的结果令vim中回删的行为和一般的编辑器没有区别。

set relativenumber number
严格来说这是两条命令。只设定number时vim会显示行号，只设定relativenumber时会显示相对行号，即以当前行为0行，向上向下1234依此排开。

vim的很多操作需要明确的行数，用相对行号则省了你还得多做一次减法的尴尬，所以我觉得更加实用一些。

至于这里把两个设定写在一行的效果则是当前行依旧显示其行号，上下两侧则是相对行号依次排开。该特性需要vim7.4版本的支持。

set wildmenu
用于命令行补完，比如在命令行输入:color再按<Tab>键所有的备选色彩方案都会以列表的形式列出，按<Tab>可以切换。

set ruler
在右下角显示光标当前的位置。

set encoding=utf8
所有文件统一成utf8的编码。

autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal g`\"" |
    \ endif
这一段可能看上去有些吓人，用了一些vim的脚本语言，大可不管它是如何工作的。

作用是打开vim时光标回到上次退出时的位置。这是个非常有用的特性，不知道为什么vim不能以更加简单的配置方式来实现，但不管如何这样确实管用。

下面几条主要和搜索匹配有关

set hlsearch
set incsearch
在nromal模式下键入/或?进入搜索模式，设定了incsearch后会实时匹配，设定了hlsearch后会高亮匹配到的结果。但是用过这个功能的也清楚，搜索完成以后高亮是不会自动消失的，很烦人，所以vim还有一个配套的命令：

set nohlearch
字面上是取消高亮的意思，因为会和前面那条冲突，肯定不能写进配置文件，所以使用的话就是搜索完成以后在命令行模式里面输入一下，高亮就没了。这条命令也比较智能，其作用只是暂时的，下次再搜索依旧会高亮显示。

不过老这么输入命令一点也不酷啊，所以这里还有一个键盘映射，配合使用，效果拔群：

nnoremap <CR> :nohlsearch<cr>
这条命令把normal模式下的回车键映射到nohlsearch上，具体的效果是你搜索完毕后按以下回车回到normal模式，再按以下回车高亮就没了。

set ignorecase
令搜索时忽略大小写。输入大写字母很痛苦，我认为这样可以省很多事。

set smartcase
输入大写字母时会严格匹配，输入小写时配合上一条也可以匹配大写。这两条可以根据自己的需要设置。

set showmatch
光标移动到某个括号上时可以自动高亮配对的另一个，写代码时很方便。

下面几条和tab有关

set expandtab
将<Tab>键换成空格。好像现在没人写程序还在用制表符了吧。

set smarttab
在行首时插入shiftwidth规定的空格数，其他地方则插入tabstop规定的空格数。

set shiftwidth=4
set tabstop=4
大意是一个tab换成几个空格，我主要写python，所以都换成了4个。有些人偏爱2个一些。

下面几条和缩进有关

set autoindent
顾名思义就是自动缩进的意思，新起一行时自动拷贝上一行的缩进。

set smartindent
智能缩进，写代码时很贴心。

set wrap
wrap的意思是比如你的窗口只有50列宽，当你一行内容超过50列时会自动折断另起一行显示，vim默认开启这个特性。而之所以这里提到这个是为了介绍真实行和显示行的区别。

所谓真实行在行尾有EOL的标记，最简单的判定方法就是看行号，行号不同的肯定是不同的两行。而上面通过wrap得到的两行只是为了看上去方便而故意显示成两行，实则还是一行，从行号上就能看出来。

filetype on
打开后vim会自动侦测编辑的文件类型，常用的类型都有支持，上面的smartindent和smarttab等功能对此有依赖。

syntax on
打开vim的高亮系统。写代码没高亮就太说不过去了。同样对文件侦测功能有依赖。vim自带了一些配色方案，可以在命令行模式下:color <Tab>查看选择。

一些个人设置
下面有一些个人设定，主要是一些映射。

自己添加映射的结果实际上是改变了vim的操作方式，除非你有足够的理由，否则请不要这样做。理由有：vim默认的操作是经过精心设计和多年检测的，里面自有一套逻辑（当然也有不合逻辑的地方），贸然改动会带来很多意想不到的冲突和问题；vim的默认操作放之四海皆准，这也是vim的优势，你改动的越多，离这个标准就越远，等于自动放弃了这份普适性。

下面这些改动之所以存在，主要是因为用的太多，而原有的操作又太过反人类。你不需要照抄，但可以当成参考。

let mapleader = '/'
vim里面有一个特殊的键叫<Leader>，特点是你可以自己定义它的值，经常在一些插件的操作中可以见到，很常用。它的默认值是\比如某个功能的快捷键是<Leader>t，可以先后按下\ t来启用这个功能。

上面的命令则把<Leader>映射到/。常用的做法其实是映射到,，但,本身和;是一对互补的功能键，放弃太可惜，所以我更喜欢/一些。

imap jj <Esc>
把insert模式中连按两次j映射到了<Esc>上，这绝对不是惯常的做法，但我觉得无比受用。

使用vim时最常见的操作恐怕就是在不同模式之间切换了，这其中<Esc>键意义重大，无奈位置太过偏远。

有人提倡把大小写键和ESC键对调，据我了解除了mac可以轻松做到这一点以外其他的系统都需要在底层做一些改动，或者需要键盘硬件的支持，我这里都不具备，况且即使可以我也会把大小写键换成ctrl的，所以必须另寻他法。

用连按两下j来代替ESC的好处是手不需要离开键盘最核心的位置就能完成操作，习惯后节奏也很好。缺点是偶尔会造成误操，鱼和熊掌不可兼得。

imap kk <C-o>
这个映射比上面的更奇葩，不过同样受用。

<C-o>的意思是Ctrl和o的组合键，在insert模式下按<C-o>同样会回到normal模式，不同的是完成一个操作后会立刻返回insert模式。

我主要用它来跳出括号用。

情况大概是这样的，我在用一个叫Atuoclose的插件，效果是输入左括号会自动补上右括号，并且光标移动到括号中间供进一步的输入。但括号里面的内容编辑完想接着编辑括号外面的内容就比较麻烦了，直接回到normal模式vim会自动将光标往前移动一位，这样就不得不先右移一位再按a来接着编辑，用<C-o>则不存在光标自动往前移动一位的问题，跟着直接按a就能跳出括号接着编辑。

这种映射下虽然跳一个括号出来要按三次键，但胜在普适性好闭着眼也能操作，熟练之后节奏很棒。

nmap Y y$
这个映射主要解决了一个vim默认设定不合逻辑的地方。

先看d这个操作，是剪切的意思，按D则会直接对光标当前的位置到行末执行剪切操作，等价于d$，c和C也有这样的性质，但唯独Y没有这个效果，那就只能自己补上了。

这里也是想说明，vim虽然操作繁多，但多数是成对出现功能互补的，并且背后有一些统领性的原则，有了这样的视角再去看vim，会发现逻辑清晰地多，记忆起来也不是那么困难了。

nmap <C-j> <C-w>j
nmap <C-k> <C-w>k
nmap <C-h> <C-w>h
nmap <C-l> <C-w>l
这一套映射简化了在分屏的不同窗口中移动光标的动作。分屏的所有操作都需要同时按下Ctrl和w键再配合其他按键，对我来说难度太大了。

map j gj
map k gk
希望你还记得前面提到的真实行和显示行的区别。vim中j和k的移动是基于真实行的，如果遇到几个显示行在一起的情况就会直接跳过去，让人有些摸不到头脑，gj和gk同样是上下移动，但基于显示行，这样映射一下操作起来顺畅很多。

下面几条主要是我针对不同文件类型的设定，供参考。

autocmd FileType python set columns=90 lines=50
这条命令的意思是，如果编辑的文件是python脚本，那么自动将窗口设定为90列乘50行大小。

autocmd FileType python set cul cuc colorcolumn=81
这里面主要有三个命令，cul和cuc分别是高亮光标所在行和所在列的意思，效果上看犹如一个十字准星，中心就是你的光标。

colorcolum=81表示高亮第81列，python不提倡一行的代码超过80列宽，所以设定了一条高亮的线供参考。

autocmd BufNewFile *.py 0r /home/kevin/document/templates/python_header.template
这条命令的效果是用vim新建python脚本时自动套用后面的模板。模板内容随意，我的只有一行：

# -*- coding: utf8 -*-
接着是关于markdown的

autocmd FileType markdown set columns=90 lines=50
autocmd BufNewFile,BufRead *.md,*.mkdn,*.markdown :set filetype=markdown
我发现vim无法正确识别markdown的文件，后面一条命令可以纠正这一点。


" 更新ctags和cscope索引
" href: http://www.vimer.cn/2009/10/把vim打造成一个真正的ide2.html
" 稍作修改，提取出DeleteFile函数，修改ctags和cscope执行命令
map <F12> :call Do_CsTag()<cr>
function! Do_CsTag()
    let dir = getcwd()

    "先删除已有的tags和cscope文件，如果存在且无法删除，则报错。
    if ( DeleteFile(dir, "tags") ) 
        return 
    endif
    if ( DeleteFile(dir, "cscope.files") ) 
        return 
    endif
    if ( DeleteFile(dir, "cscope.out") ) 
        return 
    endif

    if(executable('ctags'))
        silent! execute "!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q ."
    endif
    if(executable('cscope') && has("cscope") )
        if(g:isWin)
            silent! execute "!dir /s/b *.c,*.cpp,*.h,*.java,*.cs >> cscope.files"
        else
            silent! execute "!find . -iname '*.[ch]' -o -name '*.cpp' > cscope.files"
        endif
        silent! execute "!cscope -b"
        execute "normal :"
        if filereadable("cscope.out")
            execute "cs add cscope.out"
        endif
    endif
    " 刷新屏幕
    execute "redr!"
endfunction

function! DeleteFile(dir, filename)
    if filereadable(a:filename)
        if (g:isWin)
            let ret = delete(a:dir."\\".a:filename)
        else
            let ret = delete("./".a:filename)
        endif
        if (ret != 0)
            echohl WarningMsg | echo "Failed to delete ".a:filename | echohl None
            return 1
        else
            return 0
        endif
    endif
    return 0
endfunction

" cscope 绑定
if has("cscope")
    set csto=1
    set cst
    set nocsverb
    if filereadable("cscope.out")
        cs add cscope.out
    endif
    set csverb
    " s: C语言符号  g: 定义     d: 这个函数调用的函数 c: 调用这个函数的函数
    " t: 文本       e: egrep模式    f: 文件     i: include本文件的文件
    nmap <leader>ss :cs find s <C-R>=expand("<cword>")<CR><CR>:copen<CR>
    nmap <leader>sg :cs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <leader>sc :cs find c <C-R>=expand("<cword>")<CR><CR>:copen<CR>
    nmap <leader>st :cs find t <C-R>=expand("<cword>")<CR><CR>:copen<CR>
    nmap <leader>se :cs find e <C-R>=expand("<cword>")<CR><CR>:copen<CR>
    nmap <leader>sf :cs find f <C-R>=expand("<cfile>")<CR><CR>:copen<CR>
    nmap <leader>si :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>:copen<CR>
    nmap <leader>sd :cs find d <C-R>=expand("<cword>")<CR><CR>:copen<CR>
endif

" Quick Fix 设置
map <leader>cw :cw<cr>
map <F3> :cp<cr>
map <F4> :cn<cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => vim常用命令 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
类 型	序 号	命 令	释 义
基 本	1	:e 文件名	打开文件进行编辑
		2	:w	保存文件
		3	:q	退出vim
		4	:q!	不保存文件退出vim
搜 索	5	/word	从开始处到结尾处搜索字符串
		6	?word	从结尾处到开始处搜索字符串
		7	/jo[ha]n	搜索john或者joan
		8	/\<the	搜索the、theatre或者then，匹配以the开始的字符串
		9	/the\>	搜索the或者breathe，匹配以the结尾的字符串
		10	/\<the\>	搜索the，只匹配the
		11	/\<\w\{4}\>	匹配所有四个字母的单词
		12	/\<fred\>/	匹配fred但是不匹配alfred或者frederick
		13	/fred\|joe	匹配fred或者joe
		14	/\<\d\d\d\d\>	匹配四个数字
		15	/^\n\{3}	匹配连续的三个空行
		16	:bufdo /正则表达式/	在所有打开的文件中搜索
替 换	17	:%s/old/new/g	把文件中所有匹配old的地方替换成new
		18	:%s/old/new/gc	把文件中所有匹配old的地方替换成new，替换前提示确认
		19	:2,35s/old/new/g	把文件从第2行到第35行中所有匹配old的地方替换成new
		20	:5,$s/old/new/g	把文件从第5行到文件结束符中所有匹配old的地方替换成new
		21	:%s/^/hello/g	把每一行的开始位置替换为Hello
		22	:%s/$/Harry/g	把每一行的结束位置替换为Harry
		23	:%s/onward/forward/gi	替换onward为forward，大小写不敏感
		24	:%s/ *$//g	替换所有行末的空格为空字符串
		25	:g/string/d	删除所有匹配正则表达式string的行
		26	:v/string/d	删除所有不匹配正则表达式string的行
		27	:s/Bill/Steve/	把当前行中的Bill替换为Steve
		28	:s/Bill/Steve/g	把所有行中的Bill替换为Steve
		29	:%s/Bill/Steve/g	把所有文件中的Bill替换为Steve
		30	:s/\r//g	替换dos换行符为空字符串
		31	:s/\r/\n/g	替换dos换行符为回车
		32	:%s#<[^>]\+>##g	删除所有的html标签，保留其中的内容
		33	:%s/^\(.*\)\n\1$/\1/	替换所有连续出现两次的行为一行
		34	Ctrl+a	把光标下的数字自增1
		35	Ctrl+x	把光标下的数字自减1
		36	ggVGg?	对全文使用ROT13加密，关于ROT13，参考 ROT13_WIKI
大小写	37	Vu	选择一行，使其字母变为小写
		38	VU	选择一行，使其字母变为大写
		39	g~~	反转字母的大小写
		40	veU	选择一个单词，将其变为大写
		41	ve~	选择一个单词，将其变为小写
		42	ggguG	把所有文本变为小写
		43	:set ignorecase	搜索的时候忽略大小写
		44	:set smartcase	如果模式串中没有大写字母，则搜索的时候忽略大小写
		45	:%s/\<./\u&/g	将每个单词的第一个字母转为大写
		46	:%s/\<./\l&/g	将每个单词的第一个字母转为小写
		47	:%s/.*/\u&	将每行的第一个字母转为大写
		48	:%s/.*/\l&	将每行的第一个字母转为小写
读写文件	49	:1,10 w outfile	把1到10行保存到outfile中
		50	:1,10 w >> outfile	把1到10行追加到outfile中
		51	:r infile	插入infile的内容
		52	:23r infile	插入infile中23行以后的内容
文件浏览	53	e:.	打开内置的文件浏览器
		54	:Sex	分割窗口，并打开内置的文件浏览器
		55	:browse e	打开图形化的文件浏览器
		56	:ls	列出缓冲区的内容
		57	:cd..	到父目录
		58	:args	列出参数列表，当前文件会用方括号标注
		59	:args *.php	将当前目录下所有后缀是php的文件加入参数列表，并打开其中的第一个
		60	:grep expression *.php	返回所有包含expression的php文件列表
		61	gf	打开当前光标下的文件
与Unix系统交互	
		62	:!pwd	执行unix命令pwd，然后返回到vi中
		63	:!!pwd	执行unix命令pwd，并将结果插入到文件中
		64	:sh	暂时回到unix
		65	$exit	返回vi
对 齐	66	:%!fmt	对齐所有行
		67	!}fmt	对齐当前位置的所有行
		68	5!!fmt	对齐下面5行
标 签	69	:tabnew	新建标签
		70	gt	切换到下一个标签
		71	:tabfirst	切换到第一个标签
		72	:tablast	切换到最后一个标签
		73	:tabm n(位置)	重新排列标签
		74	tabdo %s/foo/bar/g	在每一个标签中执行命令
		75	:tab ball	把所有打开的文件放入标签
分割窗口	76	:e filename	在当前窗口中编辑文件
		77	:split filename	分割窗口并打开文件
		78	ctrl-w up arrow	将光标移到顶部的窗口
		79	ctrl-w ctrl-w	将光标移动到下一个窗口
		80	ctrl_	最大化当前窗口
		81	ctrl-w=	将所有的窗口设置为同样的大小
		82	10ctrl-w+	在当前窗口中增加10行
		83	:vsplit file	垂直分割窗口
		84	:sview file	功能与只读模式下的:split命令一样
		85	:hide	关闭当前窗口
		86	:nly	关闭除当前窗口以外的所有窗口
		87	:b 2	在当前窗口中打开第二个缓冲区的内容，具体描述请见:help b:
自动补全	88	ctrl-n ctrl-p(插入模式下)	补全单词
		89	ctrl-x ctrl-l	补全整行
		90	:set dictionary=dict	定义dict为dictionary
		91	ctrl+x ctrl+k	使用字典进行补全
标 记	92	mk	将当前位置标记为k
		93	~k	将光标移动至标记k
		94	dk	删除至标记k
缩 写	95	:ab mail mail@provider.org	定义mail为mail@provider.org的缩写
文本缩进	96	:set autoindent	打开自动缩进
		97	:set smartindent	打开智能缩进
		98	:set shiftwidth=4	定义缩进的宽度为四个空格
		99	ctrl-t,ctrl-d	插入模式下缩进/反向缩进
		100	>>	缩进
		101	<<	反向缩进
语法高亮	102	:syntax on	打开语法高亮
		103	:syntax off	关闭语法高亮k
		104	:set syntax=perl	强制打开语法高亮

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => vim cscope ctags 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Linux应用程序开发（二） ── vim+ctags+cscope
六、通用的使用 VIM+Ctags+Cscope 访问程序文件的方法

1. ctags+cscope配合使用的原因：
    为什么要配合，因为，比如cscope能提供更多的查找功能等功能。但是ctags远比cscope支持更多的文件。比如要访问一个java工程文件，那么cscope是能力低下的，比如对类识别不行，但是我们仍然可以利用其一些功能，比如找到什么函数调用了这个函数。
    另外，还有点注意，ctags不能利用QuickFix窗口，而cscope可以利用，这也是cscope的好处。一般，如果仅仅有C/C++文件，用cscope更多，如果是其他文件，则用ctags更多。
    不管是用ctags还是cscope，都可以用WinManager和Taglist，来实现左边上面是文件列表，下面是Taglist，右边是文件浏览窗口的效果！但是Taglist依赖ctags，如果用cscope，ctags还是要用的。具体的让WinManager和Taglist配合的方法，见vim配置文件。

2. 生成数据库并让vim使用：
一般的做法是：在最上层目录，生成这些文件。然后vim在最上层打开，并利用下面提到的WinManager来导航到里面目录。
(1) ctags生成tags文件：
ctags -R . 可以搜索目录下所有的文件，并生成 tags 文件。
为了生成最多的tags:
C/C++这样：ctags --extra=+q --fields=+Saim --c++-kinds=+lpx --c-kinds=+lpx -R .
Java这样：ctags --java-kinds=+l -R .

(主要是--xx-kinds控制着要分析出哪些东西，如--java-kinds=+l表示要加上(+)local variable，默认的有哪些，没有哪些，用ctags --list-kinds 可以知道，off的都是默认不分析的，否则是分析的)
cscope只能分析C/C++/lex/yacc文件！

然后在vim里 :set tags=path/to/tags（用,分隔，可以多个）

(2) cscope生成cscope.in.out cscope.out cscope.po.out文件：
由于cscope默认不看非.c .yacc .lex外的文件，所以，假设你要找C和C++其他文件，要这样：
find . -name "*.h" -o -name "*.c" -o -name "*.cc" > cscope.files
cscope -bkq -i cscope.files
（找java文件同理）
而，对于纯C文件，你可以：
cscope -Rbkq ./ 即可。

然后在vim里 :cs add path/to/cscope.out
如果要重新生成，用:!cscope -Rbkq，再用 :cs reset重新读入.

3. ctags 管理跳转栈：
ctags设计来找到各种希望找的东西，如类定义处，函数定义处。对各种语言都有支持，但原设计就是针对function定义的，所以，ctags对寻找functions定义特别有效，像函数原型是默认不做tag的。
(1) vim的支持tags的命令：（这些命令在编译时要加进ctags支持才能用）
vim靠内置的命令，来支持使用ctags得到的tags文件。
:tags 列出目前你跳转的栈，可以得知当前位置 （可惜不能用QuickFix窗口）
:tag 跳到:tags列表的顶部（栈底）
:tag tagname 跳到tagname的定义处
Ctrl+] 压栈（跳到标记定义处） Ctrl+W ] 在横着的新窗口打开(:stag tagname)
n Ctrl+t 出栈（后跳n次，会使你的:tags列出的表缩短） ── 跨文件时，用 Ctrl + o才能跳回去。

:tselect tagname 可以列出所有的相同的tagname，你按数字可以跳到对应条目。
:tnext 跳到下一个相同tagname处
:tprevious 同理
:tfirst    同理
:tlast     同理

匹配用/ /来括起来，让vim知道里面的是正则式
如 :tselect /^write_ 可以匹配以 write 开头的

:set ignorecase 可以在任何时候忽略大小写，比如在:tag tagname时。如果设置了这个，又想case有效，则在表达式后加\C
但如果想某次有效，则在表达式后面加\c
上面的表达式都用//包起来。


4. cscope看vim配置文件和以前的文档即可。

5. 使用Path：
有时，我们要定义额外的Path，以访问某些文件。且方便gf(goto file，在normal模式下，按gf，会打开光标下的文件，它会在Path下去搜），find（不支持正则式的搜索，用法 :find netrw.vim）等命令。

path选项定义了一个目录列表，在使用gf，find，以及CTRL-W f等命令时，如果使用的是相对路径，那么就会在path选项定义的目录列表中查找相应的文件。path选项以逗号分隔各目录名。我们依旧以VIM 7.0的源代码为例（源代码放在~/src/vim70/目录中）。

对于这个项目，我们的path选项设置如下：
set path=.,/usr/include,,~/src/vim70/**

稍微解释一下各项的含义，更详细的信息，请查看path选项的帮助页：
.                在当前文件所在目录中搜索 
/usr/include     在/usr/include目录中搜索 
,,               在当前工作路径中搜索 
~/src/vim70/**   在~/src/vim70的所有子目录树中进行搜索!!

6. 多文件浏览采用 MiniBufExplorer:
因为使用了WinManager和Taglist，所以tabe显得不好用了，用buffer会更方便。
但是vim自带的buffer管理工具只有:ls, :bnext, :bdelete 等的命令，这里用MiniBufExplorer.好处是在顶上可视化列出了各个buffer。仍然用:bnext等命令。
然后，在vim中设置了，用shift+Tab来切换buffer，挺方便。
关闭一个buffer，而不退出窗口，在标签上按d，这是MiniBufExplorer的命令。个

7. Taglist
提醒用 s 来切换按名字排序（大写，再小写，每个里面按首字母）还是出现次序排序
用 u 来更新list（默认可以再次调用ctags）
另外，在vimrc中设置了单击来打开对应位置

8. WinManager
s来切换按xx排序，r做反排序
另外，在各个窗口间切换，用 Ctrl+方向键 更快~~~

9. vimgrep查找文本 或 Grep插件查找文本：
ctags找到了--list-kinds中指示的东西，你可以用:tag tagname找出这些tags，cscope也找了它可以找的东西，可以用:cs find g/d/c/t/e tagname找到相应的东西，其中t表示找那个文本，尤其是e表示用egrep查找。单都是在cscope的数据库中查找。
但是，很多时候，仍需要对文件本身搜索，或者想到某个特定子目录搜索，并支持正则式。
(1) 可以用 :vimgrep命令：
:vimgrep是vim内置的grep，如果你用:grep等，则是让vim调用外部的系统的grep。用:vimgrep的好处是，不依赖于系统的，使得各个系统上都可以用。但是会慢点，因为它会把每个文件，放入buffer，再分析。
用法简单：
:vimgrep /pattern/ path
其中 pattern为正则式，如 \<main\>表示main单词
path 为shell元字符式，如 ./SSF/**/*.java 表示搜索SSF目录下，所有子目录，及所有嵌套子目录的 java文件。
(2) 也可以用Grep插件，下面命令都支持正则式:
:Grep 在指定的文件查找
:Rgrep 递归查找
:Bgrep 在打开的缓冲区中查找
他会问你更多信息，比如哪些文件中查找，在哪个目录中查找，很方便。
如：
Search for pattern: 时可以填 \<get_real_path\> （匹配单词，而不是字符串）
Search in files: 时可以填 *.java

10. 高亮文本：
:colorscheme 可以选择某个主题。
在.vim里，自己创建colors doc plugin syntax 四个目录，doc和plugin用户放plugin的文件和doc文件，syntax用于放置指导语法加亮的文件，而colors就用于放置高亮主题。目前我用的是desert主题。

11. 目前用到的插件：
a.vim              
color_sample_pack.vim 
minibufexpl.vim     
taglist.vim          
winmanager.vim (winfileexplorer.vim wintagexplorer.vim)
code_complete.vim   #这个好好看看它的代码体吧，很简单，却很高效的用tab补全很多东西，如调用函数时，在(后按tab，就可补出各个参数的类型。比如很方便自动生成main，for，while，＃define等。
grep.vim               
NERD_commenter.vim 


12. 颜色相关：
首先，在vim中输入 :runtime syntax/colortest.vim 可打印出目前你可以使用的颜色。只有那么几种。包括粗体。所以，这就是终端里使用vim没有gvim颜色多，或者没有gvim颜色正常的原因。但是，你好好调整一下，还是能够满足自己要求的。
另外，各种颜色主题，是不能让，如函数，单独高亮的，因为这需要语法帮助。这需要你单独找语法文件，就是什么东西是函数，并应该高亮为什么颜色。把语法文件放到 ~/.vim/syntax中。
我是从官网下了cpp.vim放到~/.vim/syntax目录中，于是.cpp文件可以有更多的高亮了。
但是，c.vim是我从别的地方找的，官网上找的c.vim不起作用，我又不好改。目前用的c.vim如下，主要加亮了函数名和C关键字。而cpp.vim是使用c.vim的，所以默认也就让cpp.vim支持同样的效果了。

要读懂和改这个简单文件，需要知识如下：
:hi 命令时一直都是以图形介面（gui）为例设置前景和背景色。由于命令终端对颜色显示的限制，Vim在命令行下可以使用的颜色相对gui 要少得多，所以使用:hi命令时图形介面和命令行介面的颜色是分开设置的。对于黑白终端来说就无所谓颜色了，而彩色终端用cterm来表示，前景色就是 “ctermfg”，而背景色是“ctermbg”。下面是一个表格：

终端类型 前景色      背景色      注释
term           -              -              黑白终端
cterm     ctermfg    ctermgb       彩色终端
gui          guifg        guibg          图形介面


下面是这个文件 c.vim
"========================================================
" Highlight All Function
"========================================================
syn match   cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>[^()]*)("me=e-2
syn match   cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>\s*("me=e-1
hi cFunction        gui=NONE guifg=#B5A1FF

"========================================================
" Highlight All Math Operator
"========================================================
" C math operators
syn match       cMathOperator     display "[-+\*/%=]"
" C pointer operators
syn match       cPointerOperator display "->\|\."
" C logical   operators - boolean results
syn match       cLogicalOperator display "[!<>]=\="
syn match       cLogicalOperator display "=="
" C bit operators
syn match       cBinaryOperator   display "\(&\||\|\^\|<<\|>>\)=\="
syn match       cBinaryOperator   display "\~"
syn match       cBinaryOperatorError display "\~="
" More C logical operators - highlight in preference to binary
syn match       cLogicalOperator display "&&\|||"
syn match       cLogicalOperatorError display "\(&&\|||\)="

" Math Operator
hi cMathOperator            guifg=#3EFFE2 ctermfg=lightyellow   
hi cPointerOperator         guifg=#3EFFE2 ctermfg=lightyellow 
hi cLogicalOperator         guifg=#3EFFE2 ctermfg=lightyellow 
hi cBinaryOperator          guifg=#3EFFE2 ctermfg=lightyellow 
hi cBinaryOperatorError     guifg=#3EFFE2 ctermfg=lightyellow 
hi cLogicalOperator         guifg=#3EFFE2 ctermfg=lightyellow 
hi cLogicalOperatorError    guifg=#3EFFE2 ctermfg=lightyellow 



" ------------------------ further work ------------------------
" hi cType ctermfg=green
hi cConditional ctermfg=lightred
hi cRepeat ctermfg=lightred
hi cStatement ctermfg=lightred
hi cLabel ctermfg=lightred
"hi cType ctermfg=green
hi cDefine ctermfg=magenta
hi cUndefine ctermfg=magenta
hi cFunction ctermfg=blue

" ----------------------- 以下的是备查而已 ------------------------
" hi other words later
" C language keywords.
" For compilers with asm keyword - error if not c_c_vim_compatible.
syn keyword       cKRStatement      asm
syn keyword     cGNUStatement     __asm__
syn keyword       cLabel            case default
syn keyword       cConditional      if else switch
syn keyword       cRepeat           while for do

" C data types
syn keyword       c89Type           int long short char void signed unsigned float double
" These are actually macros that expand to the above.
syn keyword     c99Type           bool complex imaginary
syn keyword     cGnuType          __label__ __complex__ __volatile__

" C language structures
syn keyword       cStructureType    typedef
syn keyword       cStructure        struct union enum

" C storage modifiers
syn keyword       c89StorageClass   static register auto volatile extern const
syn keyword       cKRStorageClass   fortran
syn keyword     c99StorageClass   restrict inline
syn keyword     cGNUStorageClass __attribute__


13. 支持tags更新：
见下面绑定在F7上的功能，就是把ctags和cscope重新更新。
这个的好处显然的，比如你想对新改的代码使用code_complete.vim插件中的功能。

14. c++补全：
omnicppcomplete 插件很好用。这个放在~/.vim里后，注意下面.vimrc文件中对它的几行设置，否则不太好似。

15. C-x C-o：
C++ 自动补全OK了，但是C的函数怎么补全呢？？ 在ctags存在的情况下，用C-x C-o吧，我棒定到F8上去了，见vimrc.   它比 C-p强的地方是，它会把函数的函数原型也列出来，方便输入，其他的找到的，也会标出类型。


强烈建议程序员完整的阅读usr_29.txt和usr_30.txt

---------------------- 下面是 2009 03 29 日vimrc文件内容：----------------------
" An example for a vimrc file.
"
" Maintainer:    Bram Moolenaar <Bram@vim.org>
" Last change:    2006 Nov 16
"
" To use it, copy it to
"     for Unix and OS/2: ~/.vimrc
"          for Amiga: s:.vimrc
" for MS-DOS and Win32: $VIM\_vimrc
"        for OpenVMS: sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
finish
endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
set nobackup        " do not keep a backup file, use versions instead
else
set backup        " keep a backup file
endif
set history=50        " keep 50 lines of command line history
set ruler        " show the cursor position all the time
set showcmd        " display incomplete commands
set incsearch        " do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" In many terminal emulators the mouse works just fine, thus enable it.
set mouse=a

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
syntax on
set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

" Enable file type detection.
" Use the default filetype settings, so that mail gets 'tw' set to 72,
" 'cindent' is on in C files, etc.
" Also load indent files, to automatically do language-dependent indenting.
filetype plugin indent on

" Put these in an autocmd group, so that we can delete them easily.
augroup vimrcEx
au!

" For all text files set 'textwidth' to 78 characters.
autocmd FileType text setlocal textwidth=78

" When editing a file, always jump to the last known cursor position.
" Don't do it when the position is invalid or when inside an event handler
" (happens when dropping a file on gvim).
autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

augroup END

else

set autoindent        " always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
         \ | wincmd p | diffthis

" ///////////////////////////////////////////////////////////////

" common options

if has("win32") 
set encoding=utf-8
set termencoding=utf-8
set fileencoding=chinese
set fileencodings=ucs-bom,utf-8,chinese 
set langmenu=zh_CN.utf-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
language messages zh_cn.utf-8 
language messages zh_cn.utf-8

set guifont=Courier_New:h12:cANSI    " 指定windows下的英文字体和大小
set guifontwide=NSimSun:h11              " 指定windows下的中文字体和大小
else
set fileencodings=utf8,gbk,big5
endif

set tabstop=4
set shiftwidth=4
set mouse=a
set backupdir=~/tmp/vim/
set scroll=10
set autoindent
set smartindent
set cindent
syntax enable
syntax on
set fdm=indent
set foldlevel=100
set number

:map <F2> :tabprevious<CR>
:map <F3> :tabnext<CR>
:imap <F2> <ESC>:tabprevious<CR>
:imap <F3> <ESC>:tabnext<CR>


" taglist and winmanager integration
let Tlist_Use_SingleClick=1
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let g:winManagerWindowLayout='FileExplorer|TagList'
map wm :WMToggle<cr>

" MiniBufferExplorer
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1 
let g:miniBufExplUseSingleClick = 1
"map <S-Tab> :bn<CR> 
"map <C-Tab> :bp<CR>

" cscope options
set cscopequickfix=s-,c-,d-,i-,t-,e-,g-
if has("cscope")
    set csprg=/usr/bin/cscope
    "use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    set cscopetag
    set csto=0
    set cst
    set nocsverb
    " add any database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    " else add database pointed to by environment
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif
    set csverb
endif

map <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR> :cw<CR>
map <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR> :cw<CR>
map <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR> :cw<CR>
map <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR> :cw<CR>
map <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR> :cw<CR>
map <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR> :cw<CR>
map <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR> :cw<CR>
map <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR> :cw<CR>

" ctags options
set tags=./tags
" au BufWritePost *.c,*.cpp,*.cc,*.h !cscope_ctags_cppfiles 
" reproduce ctags and cscope.out and reset cscope to vim.(ctags is automatically reseted)
map <F7> :!ctags --extra=+q --fields=+Saim --java-kinds=+l --c++-kinds=+lpx --c-kinds=+lpx -R . <CR><CR> :!find . -name "*.h" -o -name "*.c" -o -name "*.cc" -o -name "*.cpp"> cscope.files <CR><CR> :!cscope -bkq -i cscope.files<CR><CR> :cs reset<CR><CR>


" c/cpp complete
imap <F8> <C-X><C-O>
set completeopt=longest,menuone
let OmniCpp_DefaultNamespaces = ["std"]
let OmniCpp_NamespaceSearch = 1
let OmniCpp_MayCompleteDot = 1
let OmniCpp_MayCompleteArrow = 1
let OmniCpp_MayCompleteScope = 1
let OmniCpp_ShowScopeInAbbr = 1
let OmniCpp_ShowPrototypeInAbbr = 1

" color scheme
colorscheme desert

" other options
map <F4> :cp<CR>
map <F5> :cn<CR>
imap <F4> <ESC>:cp<CR>
imap <F5> <ESC>:cn<CR>

map <F9> :make<CR><CR><CR> :copen<CR>
map <F10> :!./a.out<CR>

map <C-a> :A<CR>
imap <C-a> <ESC>:A<CR>

map <Left> <CR> :bp<CR>
map <Right> <CR> :bn<CR>

map <C-w> :Rgrep<CR><CR><CR><CR>
imap <C-w> <ESC>:Rgrep<CR><CR><CR><CR>
---------------------------------------------------------------------------------------------
（旧）六、VIM配套工具集：
(一)用 cscope 查看源代码
生成索引，记住Rbkq就行
cscope -Rbkq
-R: 在生成索引文件时,搜索子目录树中的
代码
-b: 只生成索引文件,不进入 cscope 的界面
-k: 在生成索引文件时,不搜索 /usr/includ
e 目录
-q: 生成 cscope.in.out 和 cscope.po.out 文
件,加快 cscope 的索引速度


● cscope在Vim中的基本用法是 :cs + 子命令
:cs find {querytype} {name}
● find 的子命令
s: Find this C symbol # 记法 s - symbol，查找的是symbol，不是一般的text
g: Find this definition   # g就记住是definition
d: Find functions called by this function   # d 是 called 后那个d
c: Find functions calling this functio     # c 是 called 前那个c
t: Find this text string                   # t 是 text 的意思，就是 一般的 text 查找
e: Find this egrep pattern                 # e 正则式了 
f: Find this file                          # f 是 file 的意思
i: Find files #including this file         # i 是 include 的意思，即查找 包含此头文件的文件

当然，你可能会find很多，cs find 如果找到一个，则默认定位到那个去，如果找到多个，则会列出来，可能在本窗口列出（如果不设置在QuickFix窗口列出，默认就是这个样子，可以看看），也可能在QuickFix窗口列出，那一般是设置在QuickFix这个单独的窗口列出，见下边.vimrc设置的这一行：:set cscopequickfix=s-,c-,d-,i-,t-,e-,g- ，但默认是不打开QuickFix窗口的，所以要你自己用:cw或:copen打开后就看到结果了（关闭QuickFix可以用:cclose）。见下面的快捷键设置，我默认是打开的，最后我加了一个:cw<CR>.
不管在哪里列出，需要遍历列出的项，则用鼠标一个一个点击，或者用命令如下：
:cw （或:copen）对make,cscope等，在最后一行提示你有多个选择时，你可以用:cw来打开QuickFix窗口，用:cn定位到下一个，用:cp定位到上一个，也可以在QuickFix窗口中用上下或鼠标点击操作。当然，我为了方便，用快捷键设置了，见下面。设置到F7和F8上面了。


其他cs 的子命令：
在最后一行敲:cs你可以得到：所有的用法，一目了然，便于查找。简单说明如下：
上面的:cs 中的find子命令只是其中一个，其他的有如add常用于添加另一个cscope.out数据库文件，这样你可以用很多个，就是写上路径。
show用于显示现有的cscope连接，即你用add加成功的cscope.out数目。
reset很有用，当你改完代码后，需要重新生成cscope.out等文件 (重新生成cscope.out文件，可以用:!外部命令，这里应该是 :!cscope -Rbkq)， 这时为让vim中的cscope数据库刷新，需要:cs reset一下。
:h if_cscop.txt查看完整文档

最后，为方便使用，常为cscope的命令做map，和vim相关的.vimrc的部分如下，完整的.vimrc查看另一篇博客。

.vimrc中要写的和cscope相关的：

"这表示cs的这些子命令都使用quickfix窗口，-表示是更新quickfix窗口，而不是追加。如果写成 +，如s+就表示是对quickfix窗口追加。如果没出现在这里的命令，默认直接在当前窗口下直接列出找到的所有项。
:set cscopequickfix=s-,c-,d-,i-,t-,e-,g- 

"下面的来自 :h if_cscop.txt中的建议，不必太注意细节，只是看到里面已经把当前目录下的cscope.out加进去了。
if has("cscope")
    set csprg=/usr/local/bin/cscope
    set cscopetag
    set csto=0
    set cst
    set nocsverb
    " add any database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    " else add database pointed to by environment
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif
    set csverb
endif

"做键的映射，让cscope更方便。其中 <C-R>=expand("<cword>")<CR> 是为了让如 :cs find s 后添上当前光标处的word，你可以自己敲这个试试.
nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR> :cw<CR>
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR> :cw<CR>
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR> :cw<CR>
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR> :cw<CR>
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR> :cw<CR>
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR> :cw<CR>
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR> :cw<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR> :cw<CR>

"做键的映射，能够用F7和F8来切换QuickFix窗口中的项
map <F7> :cp<CR>
map <F8> :cn<CR>
imap <F7> <ESC>:cp<CR>
imap <F8> <ESC>:cn<CR>
" 这是为插入模式设置map， imap <F8> <ESC>:cn<CR>i 表明切换后仍为插入模式，但是我不太喜欢，有时会引起误操作，所以一般不要后面那个i。



最后，这样设置了配置文件后，就会有一些简单的用法可以用了：
ctrl-t 是本文件内的跳转到上次光标位置
ctrl-o 是跨文件的跳转（比如你上次打开一个文件，又关闭了，再打开一个新的，如果一直按这个，就会打开上次那个文件）
:ts tagname 查找所有的tagname符合的，列出，供你选择，再跳转
ctrl-] 在tagname上， 等于 :cs find g xxx



(二) 用ctags 查看源代码：
       由于ctags只是生成tags文件，不包含怎么在vim中找到某种特定的tag的命令，比如函数原型怎么找，定义怎么找等，它就是一个tags生成程序而以。而VIM本身只提供纯粹针对tags的查找（如列出所有相关tags，调到第一个符合的tags...），即不识别类，函数之类的，所以VIM+ctags不能实现复杂查找。除非有其他插件支持。且对c++支持不好，比如从类成员的使用跳到c++类成员的定义处就不行，而只能用ts列出匹配项，让你自己选，而cscope可以。
       所以最好用cscope，它本身就在最后一行模式支持多种语言中特定tag类型（如类，函数）的查找，且可以map成快捷键。

下面为用法：
1. ctags & tags：
tags是ctags生成的文件，典型形式如下：
!_TAG_FILE_FORMAT       2       /extended format; --format=1 will not append ;" to lines/
!_TAG_FILE_SORTED       1       /0=unsorted, 1=sorted, 2=foldcase/
!_TAG_PROGRAM_AUTHOR    Darren Hiebert /dhiebert@users.sourceforge.net/
!_TAG_PROGRAM_NAME      Exuberant Ctags //
!_TAG_PROGRAM_URL       http://ctags.sourceforge.net    /official site/
!_TAG_PROGRAM_VERSION   5.6     //
A       main.cpp        /^class A{$/;" c       file:
A::i    main.cpp        /^      int i;$/;"      m       class:A file:   access:private
A::ok   main.cpp        /^      ok() {$/;"      f       class:A file:   access:private signature:()
a       main.cpp        /^      unsigned char a = 0x01 | 0x08;$/;"      l
i       main.cpp        /^      int i;$/;"      m       class:A file:   access:private
main    main.cpp        /^int main() {$/;"      f       signature:()
ok      main.cpp        /^      ok() {$/;"      f       class:A file:   access:private signature:()

很容易看懂意思吧，每一行就是一个tag，后面跟出许多fields。从形式上就这米简单。
而cscope的不是这种tags形式，不太明白，没看。

2.重要信息：
ctags --list-kinds 打印出对每种语言支持识别的tags，比如C++支持类名，函数定义，函数原型...
ctags --list-languages 列出支持的语言

3.主要用法：
由于vim大约在7.0以后，支持了对你包含了的头文件中的tag的下拉菜单补全，比如你包含了一个系统头文件或你自己的文件，写出一部分再按Ctrl-P，就可以有下拉的菜单。当然，跳转等复杂特性是不支持的。即便如此，也不大需要对系统路径下的文件进行ctags扫描了，下面所述，均针对你的程序文件：
(1)简单用法：
ctags -R 在源代码顶层目录下执行，默认配置适合大多数情况.(-R = --recurse)
(2)复杂用法：
逻辑上这样的：ctags自动根据文件后缀判断是什么语言的文件，并采取相应的分析方法，所以，原则上将ctags -R对任何程序文件都适用。
但是ctags到底处理语言中的哪些tags，然后tags文件中到底包含哪些fields，这个是需要详细指定的，因为一些你想要的，默认没有设置，比如函数原型在c/c++中都默认没有去查找，所以要用--c++-kinds=+p 添加上函数原型。下面 --c++-kinds=+lpx 和 --c-kinds=+lpx 只指定要加上lpx就行了，是因为你用 ctags --list-kinds，你会发现，它写有哪些tags是默认支持的，而我发现，就lpx没有被默认支持，所以我添加这三个。 而--fields=+Saim 是往tags文件中指定哪些field，这个见man里有默认显示的field，这里是加上一些默认不显示的重要的，记住是Saim就行了！至于 --extra=+q 是为C++等增强特性：对是class的成员的tag，一律加上class名前缀，即classname::tag。
所以，这样写，如果你想支持最多的话：
ctags --extra=+q --fields=+Saim --c++-kinds=+lpx --c-kinds=+lpx -R Main.cpp
记法：3部分: q Saim 和 lpx
我把这一堆（不包括-R）做了个alias为cpptags

(三) 为什么cscope比ctags强大 ─── 因为ctags仅仅用于生成tags文件。
Cscope 是一个交互式的屏幕下使用的工具，用来帮助你:
* 无须在厚厚的程序清单中翻来翻去就可以认识一个 C 程序的工作原理。
* 无须熟悉整个程序就可以知道清楚程序 bug 所要修改的代码位置。
* 检查提议的改动 (如添加一个枚举值) 可能会产生的效果。
* 验证所有的源文件都已经作了需要的修改；例如给某一个现存的函数添加一个参数。
* 在所有相关的源文件中对一个全局变量改名。
* 在所有相关的位置将一个常数改为一个预处理符号。

----------------------------------------------------------------------------------------------------------------------------------------------
1、Cscope介绍
 
       Cscope是类似于ctags一样的工具，但可以认为她是ctags的增强版，因为她比ctags能够做更多的事。在Vim中，通过cscope的查询，跳转到指定的地方就像跳转到任何标签；她能够保存标签栈，所以通过合适的键盘映射绑定，你能够在函数向后或向前跳转，就像通常使用的tags一样。
       首次使用Cscope时，他会根据源文件生成符号数据库。然后在以后的使用中，cscope只是在源文件有改动或源文件列表不同时才会重建数据库。当在重建数据库时，未改动过的文件对应的数据库信息会从旧的数据库中拷贝过来，所以会使重建数据库快于一开始的新建数据库。
       当你在命令行下调用cscope时，你会获得一个全屏选择窗口，能够使你查询特定的内容。然而，一旦你查询的有匹配，那么就会用你默认的编辑器来编辑该源文件，但是你不能够简单的使用Ctrl+]或者:tag命令来从一个标签跳转到另一个标签。
       Vim中的cscope接口是通过以命令行形式调用完成的，然后解析查询返回的结果。最终的结果就是cscope查询结果就像通常的tags一样，这样你就可以自由跳转，就像在使用通常的tags（用ctrl+]或者:tag跳转）。
 
2、Cscope相关命令
      
所有的cscope命令都是通过向主cscope命令”:cscope”传递参数选项。她最短的缩写是”:cs”。”:scscope”命令也做同样的事情并且同时会横向分隔窗口（简称：”scs”）。
      
可用的缩写有：
add ：增加一个新的cscope数据库/链接库
              使用方法：
                     :cs add {file|dir} [pre-path] [flags]
              其中：
                     [pre-path] 就是以-p选项传递给cscope的文件路径，是以相对路径表示的文件
前加上的path，这样你不要切换到你数据库文件所在的目录也可以使用它了。
                     [flags] 你想传递给cscope的额外旗标
              实例：
                     :cscope add /root/code/vimtest/ftpd
                     :cscope add /project/vim/cscope.out /usr/local/vim
                     :cscope add cscope.out /usr/local/vim –C
 
       find ：查询cscope。所有的cscope查询选项都可用除了数字5（“修改这个匹配模式”）。
              使用方法：
                     :cs find {querytype} {name}
              其中：
                     {querytype} 即相对应于实际的cscope行接口数字，同时也相对应于nvi命令：
                            0或者s   —— 查找这个C符号
                            1或者g  —— 查找这个定义
                            2或者d  —— 查找被这个函数调用的函数（们）
                            3或者c  —— 查找调用这个函数的函数（们）
                            4或者t   —— 查找这个字符串
                            6或者e  —— 查找这个egrep匹配模式
                            7或者f   —— 查找这个文件
                            8或者i   —— 查找#include这个文件的文件（们）
              实例：（#号后为注释）
                     :cscope find c ftpd_send_resp                     # 查找所有调用这个函数的函数（们）
                     :cscope find 3 ftpd_send_resp                     # 和上面结果一样
                    
                     :cscope find 0 FTPD_CHECK_LOGIN       # 查找FTPD_CHECK_LOGIN这个符号
              执行结果如下：
                     Cscope tag: FTPD_CHECK_LOGIN                   
   #   line  filename / context / line
   1     19  ftpd.h <<GLOBAL>>
             #define FTPD_CHECK_LOGIN() /
   2    648  ftpd.c <<ftpd_do_pwd>>
             FTPD_CHECK_LOGIN();
   3    661  ftpd.c <<ftpd_do_cwd>>
             FTPD_CHECK_LOGIN();
   4    799  ftpd.c <<ftpd_do_list>>
             FTPD_CHECK_LOGIN();
   5    856  ftpd.c <<ftpd_do_nlst>>
             FTPD_CHECK_LOGIN();
   6    931  ftpd.c <<ftpd_do_syst>>
             FTPD_CHECK_LOGIN();
   7    943  ftpd.c <<ftpd_do_size>>
             FTPD_CHECK_LOGIN();
   8    960  ftpd.c <<ftpd_do_dele>>
             FTPD_CHECK_LOGIN();
   9    981  ftpd.c <<ftpd_do_pasv>>
             FTPD_CHECK_LOGIN();
Enter nr of choice (<CR> to abort):
然后输入最前面的序列号即可。
 
       help ：显示一个简短的摘要。
              使用方法：
              :cs help
 
       kill  ：杀掉一个cscope链接（或者杀掉所有的cscope链接）
              使用方法：
              :cs kill {num|partial_name}
              为了杀掉一个cscope链接，那么链接数字或者一个部分名称必须被指定。部分名
称可以简单的是cscope数据库文件路径的一部分。要特别小心使用部分路径杀死一个cscope链接。
 
              假如指定的链接数字为-1，那么所有的cscope链接都会被杀掉。
 
       reset：重新初始化所有的cscope链接。
              使用方法：
              :cs reset
 
       show：显示cscope的链接
              使用方法：
              :cs show
 
       假如你在使用cscope的同时也使用ctags，|:cstag|可以允许你在跳转之前指定从一个或另一个中查找。例如，你可以选择首先从cscope数据库中查找，然后再查找你的tags文件（由ctags生成）。上述执行的顺序取决于|csto|的值。
       |:cstag|当从cscope数据库中查找标识符时等同于“:cs find g”。
       |:cstag|当从你的tags文件中查找标识符时等同于“|:tjump|”。
 
3、Cscope选项
 
       使用|:set|命令来设置cscope的所有选项。理想情况是，你可以在你的启动文件中做这件事情（例如：.vimrc）。有些cscope相关变量只有在|.vimrc|中才是合法的。在vim已经启动之后再来设置它们没有任何作用！
       ‘cscopeprg’指定了执行cscpoe的命令。默认是”cscope”。例如：
              :set csprg=/usr/local/bin/cscope
 
       ‘cscopequickfix’指定了是否使用quickfix窗口来显示cscope的结果。这是一组用逗号分隔的值。每项都包含于|csope-find|命令（s, g, d, c, t, e, f, 或者i）和旗标（+, -或者0）。
       ‘+’预示着显示结果必须追加到quickfix窗口。
       ‘-’隐含着清空先前的的显示结果，’0’或者不设置表示不使用quickfix窗口。查找会从开始直到第一条命令出现。默认的值是””（不使用quickfix窗口）。下面的值似乎会很有用：”s-,c-,d-,i-,t-,e-”。
 
       假如’cscopetag’被设置，然后诸如”:tag”和ctrl+]和”vim -t”等命令会始终使用|:cstag|而不是默认的:tag行为。通过设置’cst’，你将始终同时查找cscope数据库和tags文件。默认情况是关闭的，例如：
              :set cst
              :set nocst
 
       ‘csto’
       ‘csto’的值决定了|:cstag|执行查找的顺序。假如’csto’被设置为0，那么cscope数据将会被优先查找，假如cscope没有返回匹配项，然后才会查找tag文件。反之，则查找顺序相反。默认值是0，例如：
              :set csto=0
              :set csto=1
 
       假如’cscopeverbose’没有被设置（默认情况是如此），那么当在增加一个cscope数据库时不会显示表示表示执行成功或失败的信息。理想情况是，在增加cscope数据库之前，你应该在你的|.vimrc|中重置此选项，在增加完之后，设置它。此后，当你在vim中增加更多的数据库时，你会得到（希望是有用的）信息展示数据库增加失败。例如：
              :set csverb
              :set nocsverb
 
       ‘cspc’的值决定了一个文件的路径的多少部分被显示。默认值是0，所以整个路径都会被显示。值为1的话，那么就只会显示文件名，不带路径。其他值就会显示不同的部分。例如：
              :set cspc=3
       将会显示文件路径的最后3个部分，包含这个文件名本身。
 
4、在Vim中怎么使用cscope
 
       你需要做的第一步就是为你的源文件建立一个cscope数据库。大多数情况下，可以简单的使用”cscope –b”。
       假设你已经有了一个cscope数据库，你需要将这个数据库“增加”进Vim。那将会建立一个cscope“链接”并且使它能够被Vim所使用。你可以在你的.vimrc文件中做这件事，或者在Vim启动之后手动地做。例如，为了增加数据库”cscope.out”，你可以这样做：
              :cs add cscope.out
       你可以通过执行”:cs show”来再次检查以上执行的结果。这将会产生如下的输出：
       # pid      database name                       prepend path
 0 11453  cscope.out                             <none>
 
提示：
由于微软的RTL限制，Win32版本会显示0而不是真正的pid。
 
一旦一个cscope链接建立之后，你可以查询cscope并且结果会反馈给你。通过命令”:cs find”来进行查找。例如：
       :cs find g FTPD_CHECK_LOGIN
执行以上命令可能会变得有点笨重的，因为它要做相当的输入次数。假如有不止一个匹配项，你将会被提供一个选择屏幕来选择你想匹配的项。在你跳转到新位置之后，可以简单的按下ctrl+t就会返回到以前的一个。
 
5、建议的用法
 
       将如下内容放置到你的.vimrc中：
       if has("cscope")
              set csprg=/usr/local/bin/cscope
              set csto=0
              set cst
              set nocsverb
              " add any database in current directory
              if filereadable("cscope.out")
                  cs add cscope.out
              " else add database pointed to by environment
              elseif $CSCOPE_DB != ""
                  cs add $CSCOPE_DB
              endif
              set csverb
       endif
 
       通过设置’cscopetag’，我们已经有效的将所有:tag的情况都替换为:cstag。这包括:tag、ctrl+]，和”vim -t”。然后，正常的tag命令就会不光在tag文件中查找，也会在cscope数据库中查找。
       有些用户可能想保留常规的tag行为并且有一个不同的快捷方式来使用:cstag。例如，可以使用如下命令来映射ctrl+_（下划线）到:cstag：
              map <C-_> : cstag <C-R>=expand(“<cword>”)<CR><CR>
 
       一些经常用cscope查找（使用”:cs find”）是查找调用某一特定函数的所有函数，和查找所有出现特定C符号的地方。为了做这些事，你可以使用如下的键盘映射作为例子：
              map g<C-]> :cs find 3 <C-R>=expand(“<cword>”)<CR><CR>
              map g<C-/> :cs find 0 <C-R>=expand(“<cword>”)<CR><CR>
 
       这些给ctrl+]（右中括号）和ctrl+/（反斜杠）的映射可以允许你将光标放置到函数名称或者C符号上然后执行快速cscope查找匹配。
 
       或者你可以使用如下方案（很好用，可以将其添加到.vimrc中）：
    nmap <C-_>s :cs find s <C-R>=expand("<cword>")<CR><CR>
    nmap <C-_>g :cs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <C-_>c :cs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <C-_>t :cs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-_>e :cs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-_>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
    nmap <C-_>i :cs find i <C-R>=expand("<cfile>")<CR><CR>
    nmap <C-_>d :cs find d <C-R>=expand("<cword>")<CR><CR>
 
       “ 使用’ctrl – 空格’，然后查找时就会使vim水平分隔窗口，结果显示在
       “ 新的窗口中
              nmap <C-Space>s :scs find s <C-R>=expand("<cword>")<CR><CR>
    nmap <C-Space>g :scs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <C-Space>c :scs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <C-Space>t :scs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-Space>e :scs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-Space>f :scs find f <C-R>=expand("<cfile>")<CR><CR>
    nmap <C-Space>i :scs find i <C-R>=expand("<cfile>")<CR><CR>
    nmap <C-Space>d :scs find d <C-R>=expand("<cword>")<CR><CR>
      
       “ 两次按下’ ctrl – 空格’，然后查找时就会竖直分隔窗口而不是水平分隔
              nmap <C-Space><C-Space>s
                     /:vert scs find s <C-R>=expand("<cword>")<CR><CR>
       nmap <C-Space><C-Space>g
              /:vert scs find g <C-R>=expand("<cword>")<CR><CR>
       nmap <C-Space><C-Space>c
              /:vert scs find c <C-R>=expand("<cword>")<CR><CR>
       nmap <C-Space><C-Space>t
              /:vert scs find t <C-R>=expand("<cword>")<CR><CR>
       nmap <C-Space><C-Space>e
              /:vert scs find e <C-R>=expand("<cword>")<CR><CR>
       nmap <C-Space><C-Space>i
              /:vert scs find i <C-R>=expand("<cfile>")<CR><CR>
       nmap <C-Space><C-Space>d
              /:vert scs find d <C-R>=expand("<cword>")<CR><CR>
      
6、结合实际来使用cscope
 
       我这里有一个ftp服务器的工程，主要文件如下（Secure CRT vt100, traditional, 13）：  

       下面就是要cscope命令来建立数据库文件（多了3个和cscope相关的文件）：
 

       说明：
a、  cscope的选项分析：
-R     ：表示包含此目录的子目录，而非仅仅是当前目录；
-b     ：此参数告诉cscope生成数据库后就自动退出；
-q     ：生成cscope.in.out和cscope.po.out文件，加快cscope的索引速度
可能会用到的其他选项：
-k     ：在生成索引时，不搜索/usr/include目录；
-i      ：如果保存文件列表的文件名不是cscope.files时，需要加此选项告诉cscope到哪里去找源文件列表；
-I dir ：在-I选项指出的目录中查找头文件
-u     ：扫描所有文件，重新生成交叉索引文件；
-C     ：在搜索时忽略大小写；
-P path：在以相对路径表示的文件前加上的path，这样你不用切换到你数据库文件的目录也可以使用它了。
说明：要在VIM中使用cscope的功能，需要在编译Vim时选择”+cscope”。Vim的cscope接口会先调用cscope的命令行接口，然后分析其输出结果找到匹配处显示给用户。
 
b、  若是不指定-b选项，则在建立完数据库后进入如下界面： 
 

这里是想要查找C符号：FTPD_CHECK_LOGIN，你可以通过按Tab键来进行匹配内容和输入项的切换。按下ctrl+d退出。
注意：在此时，不可以使用ctrl+]进行跳转！
 
下面用Vim打开其中的一个文件进行编辑，然后看看使用cscope的具体例子：
输入：vim ftpd.c
                
看到此时光标在ftpd_help这个函数声明上，现在若我们想要看看这个函数是怎么实现的，可以有如下方法：
1）直接按下ctrl+]                     # 就是按下ctrl键的同时按下’]’键
2）按下ctrl+_g                          # 按下 ctrl键和下划线（同时按下shift和’-’键）和g
3）输入“:cs find g ftpd_help”后回车
4）输入“:tag ftpd_help”         # 假如有安装ctag的话
然后就会进行跳转：
           
       小结：在非windows系统上很多人都会选择强大的Vim作为编辑器，同时，我们要是能够用好那些同样强大的插件的话，那提高的战斗力可不止一点哦。常常会听到类似的抱怨，linux下没有好用的IDE，殊不知，用Vim结合一些插件，同样可以拥有IDE的强大功能，看代码也不错，可以有类似source insight的功能。这里展示下我的Vim，可能有些简陋，但至少有了些IDE的影子了：
       
 
       对了，还有一点：默认情况下cscope值会在当前目录下针对c、iex和yacc（扩展名分别为.c、.h、.I、.y）程序文件进行解析（如果指定了-R参数则包含其自身的子目录）。这样出现的问题就是，我们对于C++或Java文件怎么办，解决方案是：我们可以生成一个名为cscope.finds的文件列表，并交由cscope去解析。在Linux系统中，生成这个文件列表的方法是：
              find . –name “*.java” > cscope.files
       然后运行cscope –b 命令重新生成数据库就OK了。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => pathogen插件 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
git pull origin master
git submodule foreach pull git origin master
git submodule init
git submodule update
以上用来更新项目

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
"git submodule add https://github.com/sontek/rope-vim.git bundle/rope-vim
....
....
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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => CtrlP 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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
[\/]\.(git|hg|svn)$',
"    \ 'file': '\v\.(exe|so|dll)$'"    \ 'dir':  '\v,
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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Ycm 插件 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"//转换
"find . -name "*.h" -type f -exec sh -c "iconv -c  -f GBK -t UTF8 {} > {}.hutf8" \;
"find . -name "*.cpp" -type f -exec sh -c "iconv -c -f GBK -t UTF8 {} > {}.cpputf8" \;
"find . -name "*.c" -type f -exec sh -c "iconv -c -f GBK -t UTF8 {} > {}.cutf8" \;
"//把没用的bak文件删掉
"find . -name "*.h" -type f | xargs rm -rf
"find . -name "*.c" -type f | xargs rm -rf
"find . -name "*.cpp" -type f | xargs rm -rf
"//最后把转码之后的文件改名回正确名字，sed返回正确名字列表，在mv之前应该都是不存在的，例如xxx.h，这个时候应该还是xxx.h.hutf8 {}表示的就是要改成的最终文件名字
"find . -name "*.hutf8" -type f | sed 's/.hutf8$//' | xargs -I {} mv {}.hutf8 {}
"find . -name "*.cpputf8" -type f | sed 's/.cpputf8$//' | xargs -I {} mv {}.cpputf8 {}
"find . -name "*.cutf8" -type f | sed 's/.cutf8$//' | xargs -I {} mv {}.cutf8 {}

"install_name_tool -change  old new MacVim
"otool -L 查看
更改之前，zshrc中，要把PATH里面/usr/local/bin 放在/usr/bin 前面，否则找不到对的ctags
更改vim用的系统python为自行安装的python
 1.首先查看用的哪个python
 otool -L /usr/local/Cellar/macvim/7.4-99/MacVim.app/Contents/MacOS/Vim       13:44:08  08-04
 /usr/local/Cellar/macvim/7.4-99/MacVim.app/Contents/MacOS/Vim:
 /System/Library/Frameworks/Python.framework/Versions/2.7/Python (compatibility version 2.7.0, current version 2.7.10)
 /System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation (compatibility version 150.0.0, current version 1256.14.0)
 /System/Library/Frameworks/Cocoa.framework/Versions/A/Cocoa (compatibility version 1.0.0, current version 22.0.0)
 /System/Library/Frameworks/Carbon.framework/Versions/A/Carbon (compatibility version 2.0.0, current version 157.0.0)
 /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
 /usr/lib/libncurses.5.4.dylib (compatibility version 5.4.0, current version 5.4.0)
 /usr/lib/libiconv.2.dylib (compatibility version 7.0.0, current version 7.0.0)
 /usr/local/opt/luajit/lib/libluajit-5.1.2.dylib (compatibility version 2.0.0, current version 2.0.4)
 /System/Library/Perl/5.18/darwin-thread-multi-2level/CORE/libperl.dylib (compatibility version 5.18.0, current version 5.18.2)
 /System/Library/Frameworks/Tcl.framework/Versions/8.5/Tcl (compatibility version 8.5.0, current version 8.5.9)
 /System/Library/Frameworks/Ruby.framework/Versions/2.0/usr/lib/libruby.2.0.0.dylib (compatibility version 2.0.0, current version 2.0.0)
 /System/Library/Frameworks/AppKit.framework/Versions/C/AppKit (compatibility version 45.0.0, current version 1404.34.0)
 /System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices (compatibility version 1.0.0, current version 728.6.0)
 /System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 1256.1.0)
 /usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)
 2.更改之
 sudo install_name_tool -change  /System/Library/Frameworks/Python.framework/Versions/2.7/Python /usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/Python /usr/local/Cellar/macvim/7.4-99/MacVim.app/Contents/MacOS/Vim
 改完之后
 otool -L /usr/local/Cellar/macvim/7.4-99/MacVim.app/Contents/MacOS/Vim       13:49:47  08-04
 /usr/local/Cellar/macvim/7.4-99/MacVim.app/Contents/MacOS/Vim:
 /usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/Python (compatibility version 2.7.0, current version 2.7.10)
 /System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation (compatibility version 150.0.0, current version 1256.14.0)
 /System/Library/Frameworks/Cocoa.framework/Versions/A/Cocoa (compatibility version 1.0.0, current version 22.0.0)
 /System/Library/Frameworks/Carbon.framework/Versions/A/Carbon (compatibility version 2.0.0, current version 157.0.0)
 /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
 /usr/lib/libncurses.5.4.dylib (compatibility version 5.4.0, current version 5.4.0)
 /usr/lib/libiconv.2.dylib (compatibility version 7.0.0, current version 7.0.0)
 /usr/local/opt/luajit/lib/libluajit-5.1.2.dylib (compatibility version 2.0.0, current version 2.0.4)
 /System/Library/Perl/5.18/darwin-thread-multi-2level/CORE/libperl.dylib (compatibility version 5.18.0, current version 5.18.2)
 /System/Library/Frameworks/Tcl.framework/Versions/8.5/Tcl (compatibility version 8.5.0, current version 8.5.9)
 /System/Library/Frameworks/Ruby.framework/Versions/2.0/usr/lib/libruby.2.0.0.dylib (compatibility version 2.0.0, current version 2.0.0)
 /System/Library/Frameworks/AppKit.framework/Versions/C/AppKit (compatibility version 45.0.0, current version 1404.34.0)
 /System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices (compatibility version 1.0.0, current version 728.6.0)
 /System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 1256.1.0)
 /usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)
 3.再查看ycm核心so
 otool -L ~/.vim/bundle/YouCompleteMe/third_party/ycmd/ycm_core.so            13:49:52  08-04
 /Users/zhenghaishu/.vim/bundle/YouCompleteMe/third_party/ycmd/ycm_core.so:
 @rpath/ycm_core.so (compatibility version 0.0.0, current version 0.0.0)
 /System/Library/Frameworks/Python.framework/Versions/2.7/Python (compatibility version 2.7.0, current version 2.7.10)
 @loader_path/libclang.dylib (compatibility version 1.0.0, current version 0.0.0)
 /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
 /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
 4.更改之
 sudo install_name_tool -change  /System/Library/Frameworks/Python.framework/Versions/2.7/Python /usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/Python ~/.vim/bundle/YouCompleteMe/third_party/ycmd/ycm_core.so
 改完之后
 otool -L ~/.vim/bundle/YouCompleteMe/third_party/ycmd/ycm_core.so            13:51:13  08-04
 /Users/zhenghaishu/.vim/bundle/YouCompleteMe/third_party/ycmd/ycm_core.so:
 @rpath/ycm_core.so (compatibility version 0.0.0, current version 0.0.0)
 /usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/Python (compatibility version 2.7.0, current version 2.7.10)
 @loader_path/libclang.dylib (compatibility version 1.0.0, current version 0.0.0)
 /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
 /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
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

"给~/.vimrc添加内容：
"let g:ycm_error_symbol = '>>'
"let g:ycm_warning_symbol = '>*'
"nnoremap gl :YcmCompleter GoToDeclaration<CR>
"nnoremap gf :YcmCompleter GoToDefinition<CR>
"nnoremap gg :YcmCompleter GoToDefinitionElseDeclaration<CR>
"nmap <F4> :YcmDiags<CR>
"能得到： * >>表示行有错误 * >*表示行有警告 * gl gf gg就是找代码定义声明 * f4是打开编译窗口(fn+F4)
"让配色cool一点YCM


底下另一种配置
set completeopt=longest,menu	"让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
autocmd InsertLeave * if pumvisible() == 0|pclose|endif	"离开插入模式后自动关闭预览窗口
inoremap <expr> <CR>       pumvisible() ? "\<C-y>" : "\<CR>"	"回车即选中当前项
"上下左右键的行为 会显示其他信息
inoremap <expr> <Down>     pumvisible() ? "\<C-n>" : "\<Down>"
inoremap <expr> <Up>       pumvisible() ? "\<C-p>" : "\<Up>"
inoremap <expr> <PageDown> pumvisible() ? "\<PageDown>\<C-p>\<C-n>" : "\<PageDown>"
inoremap <expr> <PageUp>   pumvisible() ? "\<PageUp>\<C-p>\<C-n>" : "\<PageUp>"
" 跳转到定义处
nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR>
nnoremap <F6> :YcmForceCompileAndDiagnostics<CR>	"force recomile with syntastic
" nnoremap <leader>lo :lopen<CR>	"open locationlist
" nnoremap <leader>lc :lclose<CR>	"close locationlist
inoremap <leader><leader> <C-x><C-o>

let g:ycm_global_ycm_extra_conf = '~/.vim/data/ycm/.ycm_extra_conf.py'
" 不显示开启vim时检查ycm_extra_conf文件的信息  
let g:ycm_confirm_extra_conf=0
" 开启基于tag的补全，可以在这之后添加需要的标签路径  
let g:ycm_collect_identifiers_from_tags_files=1
"注释和字符串中的文字也会被收入补全
let g:ycm_collect_identifiers_from_comments_and_strings = 0
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

" SirVer/ultisnips 代码片断
" Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"
let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
let g:UltiSnipsListSnippets="<c-e>"
"定义存放代码片段的文件夹，使用自定义和默认的，将会的到全局，有冲突的会提示
let g:UltiSnipsSnippetDirectories=["bundle/vim-snippets/UltiSnips"]

" 参考https://github.com/Valloric/YouCompleteMe/issues/36#issuecomment-62941322
" 解决ultisnips和ycm tab冲突，如果不使用下面的办法解决可以参考
" https://github.com/Valloric/YouCompleteMe/issues/36#issuecomment-63205056的配置
" begin
" let g:ycm_key_list_select_completion=['<C-n>', '<Down>']
" let g:ycm_key_list_previous_completion=['<C-p>', '<Up>']
" let g:UltiSnipsExpandTrigger="<Tab>"
" let g:UltiSnipsJumpForwardTrigger="<Tab>"                                           
" let g:UltiSnipsJumpBackwardTrigger="<S-Tab>"
" end
" UltiSnips completion function that tries to expand a snippet. If there's no
" snippet for expanding, it checks for completion window and if it's
" shown, selects first element. If there's no completion window it tries to
" jump to next placeholder. If there's no placeholder it just returns TAB key 
function! g:UltiSnips_Complete()
    call UltiSnips#ExpandSnippet()
    if g:ulti_expand_res == 0
        if pumvisible()
            return "\<C-n>"
        else
            call UltiSnips#JumpForwards()
            if g:ulti_jump_forwards_res == 0
               return "\<TAB>"
            endif
        endif
    endif
    return ""
endfunction

au BufEnter * exec "inoremap <silent> " . g:UltiSnipsExpandTrigger . " <C-R>=g:UltiSnips_Complete()<cr>"

" Expand snippet or return
let g:ulti_expand_res = 1
function! Ulti_ExpandOrEnter()
    call UltiSnips#ExpandSnippet()
    if g:ulti_expand_res
        return ''
    else
        return "\<return>"
endfunction

" Set <space> as primary trigger
inoremap <return> <C-R>=Ulti_ExpandOrEnter()<CR>

作者主页的一个列表设定
The g:ycm_extra_conf_globlist option

This option is a list that may contain several globbing patterns. If a pattern starts with a ! all .ycm_extra_conf.py files matching that pattern will be blacklisted, that is they won't be loaded and no confirmation dialog will be shown. If a pattern does not start with a ! all files matching that pattern will be whitelisted. Note that this option is not used when confirmation is disabled using g:ycm_confirm_extra_conf and that items earlier in the list will take precedence over the later ones.

Rules:

* matches everything
? matches any single character
[seq] matches any character in seq
[!seq] matches any char not in seq
Example:

let g:ycm_extra_conf_globlist = ['~/dev/*','!~/*']
The first rule will match everything contained in the ~/dev directory so .ycm_extra_conf.py files from there will be loaded.
The second rule will match everything in the home directory so a .ycm_extra_conf.py file from there won't be loaded.
As the first rule takes precedence everything in the home directory excluding the ~/dev directory will be blacklisted.
NOTE: The glob pattern is first expanded with Python's os.path.expanduser() and then resolved with os.path.abspath() before being matched against the filename.

Default: []

let g:ycm_extra_conf_globlist = []

语意补全要正确工作，需要配置好.ycm_extra_conf.py文件。 可以使用YcmDebugInfo 查看具体加载了哪个配置文件。加载顺序：

1. 本目录下
2. 本工程下（git管理）
3. 根目录（home）
4. global

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => NERDTree 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" plugin - NERD_tree.vim 以树状方式浏览系统中的文件和目录

" :ERDtree 打开NERD_tree         :NERDtreeClose    关闭NERD_tree

" o 打开关闭文件或者目录         t 在标签页中打开

" T 在后台标签页中打开           ! 执行此文件

" p 到上层目录                   P 到根目录

" K 到第一个节点                 J 到最后一个节点

" u 打开上层目录                 m 显示文件系统菜单（添加、删除、移动操作）

" r 递归刷新当前目录             R 递归刷新当前根目录

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => gundo 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"{
	try
		" undo 历史保存路径 需要自己创建 mkdir -P ~/.vim_runtime/temp_dirs/undodir
    	set undodir=~/.vim_runtime/temp_dirs/undodir
    	" 开启保存 undo 历史功能
    	set undofile
	catch
	endtry
"}
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => signature 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"常用的操作也就如下几类：
"书签设定。mx，设定/取消当前行名为 x 的标签；m,，自动设定下一个可用书签名，前面提说，独立书签名是不能重复的，在你已经有了多个独立书签，当想再设置书签时，需要记住已经设定的所有书签名，否则很可能会将已有的书签冲掉，这可不好，所以，vim-signature 为你提供了 m, 快捷键，自动帮你选定下一个可用独立书签名；mda，删除当前文件中所有独立书签。
"书签罗列。ms，罗列出当前文件中所有书签，选中后回车可直接跳转；
"书签跳转。mn，按行号前后顺序，跳转至下个独立书签；mp，按行号前后顺序，跳转至前个独立书签。书签跳转方式很多，除了这里说的行号前后顺序，还可以基于书签名字母顺序跳转、分类书签同类跳转、分类书签不同类间跳转等等。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => protodef 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:protodefprotogetter='~/.vim/bundle/vim-protodef.vim/pullproto.pl'
 " 成员函数的实现顺序与声明顺序一致
let g:disable_protodef_sorting=1
"MyClass.cpp 中我键入 protodef 定义的快捷键 <leader>PP，自动生成了函数框架。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => easymotion 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"sudo git submodule add https://github.com/easymotion/vim-easymotion.git bundle/vim-easymotion
"easymotion 只做一件事：把满足条件的位置用 [A~Za~z] 间的标签字符标出来，找到你想去的位置再键入对应标签字符即可快速到达。比如，上面的例子，假设光标在行首，我只需键入 <leader><leader>fa （为避免与其他快捷键冲突，easymotion 采用两次 <leader> 作为前缀键），所有的字符 a 都被重新标记成 a、b、c、d、e、f 等等标签（原始内容不会改变），f 标签为希望移动去的位置，随即键入 f 即可到达。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => CtrlSF 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => YankRing 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"在vim裡面，copy只有一次的歷史紀錄， 
"如果希望能夠保留copy的歷史紀錄，就可以用這個plugin

"這個plugin也提供了非常好用「歷史替代」的功能。

"把這個plugin裝好之後，試試多copy幾段文字， 
"然後在normal mode按p貼上，然後再按<c-p>或<c-n>， 
"就會把剛才貼上的文字替換再前一次歷史的文字。
"非常好用，強力推薦。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => bufexplorer 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" plugin - bufexplorer.vim Buffers切换
" \be 全屏方式查看全部打开的文件列表
" \bv 左右方式查看   \bs 上下方式查看

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => NERD_commenter 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" plugin - NERD_commenter.vim   注释代码用的，

" [count],cc 光标以下count行逐行添加注释(7,cc)

" [count],cu 光标以下count行逐行取消注释(7,cu)

" [count],cm 光标以下count行尝试添加块注释(7,cm)

" ,cA 在行尾插入 /* */,并且进入插入模式。 这个命令方便写注释。

" 注：count参数可选，无则默认为选中行或当前行


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => surround 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
替换：change surround
cs命令是change surround的缩写，可以对指定的文本的外部包围字符进行替换，命令接受两个参数： 第一个是被替换的外部包围字符，第二个是要替换为的字符。替换时光标需要移动到被包围的文本内。 比如需要将字符串'test'外部的包围字符'替换为"，可以将光标移动到文本区域内，然后使用cs'"即可 下面是一些例子，部分来自帮助文件，其中的*号代表光标位置 
注意 命令中使用形如()、{}、[]的字符的左半部分和右半部分是有区别的， 区别在于处理中的头部和尾部的空格的处理，考虑例子6、7、8、9的情况，处理字符串(   test   )， 字符串有3个头部空格，有2个尾部空格。 
规则 规则可以总结如下： 
1.第一个参数使用符号的左半部分，会自动删除所有的头部和尾部 的空格，使用右半部分则不对空格进行处理 
2.第二个参数使用符号的左半部分，会自动在左半部分的后面和右半部分的前面插入一个空格 
注意例子8中的空格个数，被自动插入了空格

样例序号	原始文本	执行命令	执行结果
1	"Hello*world!"			cs"'	'Helloworld!'
2	"Hello*world!"			cs"<q>	<q>Helloworld!</q>
3	(( Hello*world! ))		cs(*	(*Hello*world!*)
4	(( Hello*world! ))		cs( *	(* Hello*world! *)
5	<div>Yo!*</div>			cst<p>	<p>Yo!</p>
6	(   test   )			cs([	[ test ]
7	(   test   )			cs(]	[test]
8	(   test   )			cs)[	[    test    ]
9	(   test   )			cs)]	[   test   ]
删除：delete surround
ds命令是delete surround的缩写，该命令只接受一个参数，即为需要删除的外部包围字符 如果需要删除文本外部的标签，可以使用字符t来指代标签，不需要输入标签全称 下面是一些例子： 
注意 命令中使用形如()、{}、[]的字符的左半部分和右半部分是有区别的， 规则同cs命令的规则1，即同样遵守第一个参数的规则，不再举例示范

样例序号	原始文本	执行命令	执行结果
1	"Hello*world!"	ds"	Hello world!
2	((Hello*world!))	ds{	(Hello*world!)
2	(123+4*56)/2	ds)	123+456/2
3	<div>Yo!*</div>	dst	Yo!
添加：you surround
ys命令是you surround（按作者的说法），可以对指定的文本进行包围，命令接受两个参数： 第一个是指示文本范围或者移动位置的文本对象，第二个是包围操作使用的字符。插入时光标需要移动到被包围的文本内。 比如需要将字符串test添加外部包围字符'，可以将光标移动到文本区域内，然后使用ysaw"即可，其中aw会被当作vim文本对象， ys模式有一种变形，即yss和ySS，操作的对象是当前行，不过yss的包围符号添加在行首行尾，而ySS的符号会插入两个新行来包围。 下面是一些例子，部分来自帮助文件，其中的*号代表光标位置 
指定范围的两种方法 
1.文本对象，规则基本同vim的文本对象规则一样 
2.移动位置，可以使用^、$、f等命令来指定位置，作用范围是当前光标到指定的位置 
注意 命令中使用形如()、{}、[]的字符的左半部分和右半部分是有区别的， 规则同cs命令的规则2，即同样遵守第二个参数的规则，不再举例示范

样例序号	原始文本	执行命令	执行结果
1	test	ysiw'	'test'
2	'test'	ysi')	'(test)'
3	'test'	ysa')	('test')
4	foo*testbar	ystb)	foo(test)bar
5	test	ysaw<p class="example">	<p class="example">test</p>
可视模式命令
可视模式下可以选择需要的文本块，然后使用命令S，就可以输入用来进行包围的字符，不再赘述。

插入模式命令
插件的插入模式还处于试验状态，可以在插入模式下插入字符对，不过我并没有测试成功。通过map命令查看文档中的按键绑定，发现并未绑定函数。

定制插件行为
插件提供对符号的行为进行定制的功能，如果需要定制'-'符号在php文件中的功能，则按下面步骤操作

" 1.使用vim函数获得ascii码
:echo char2nr("-")
" 2.在vim文件中添加绑定，并使用文件类型侦测
" 注意b:surround_45使用了'-'的ascii码值45
autocmd FileType php let b:surround_45 = "<?php \r ?>"
如果文件类型是php，则在字符串 print "Hello *world!"上执行yss-即可得到<?php print "Hello world!" ?>。使用如下方式还可以请求用户输入，jekyll的语法高亮使用highlight语法来完成，每次输入较麻烦，可以在vimrc中加入下面的设置

let g:surround_45 = "{% hightlight \1代码语言: \1 %}\r{% endhighlight %}"
这样就自定义了字符"-"的包围语法模板，比如在testtest上使用ySS-，会显示“代码语言：”并等待用户输入，输入bash，则得到下面的代码 其中的"\1代码语言: \1"被替换为用户输入的字符串，"\r"被替换为用户选择的需要被包围的文本，其余的均原样输出， 如果需要，可以在语法模板中使用换行等转义字符。语法模板也支持正则表达式的处理，但是语法过于古怪和丑陋，个人认为没有使用的价值。

{% highlight bash %}
testtest
{% endhighlight %}
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Ag 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
sudo brew install the_silver_searcher
忽略特定文件
let g:ag_prg="ag --vimgrep --smart-case  --ignore tags"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Syntastic 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
在vim中安装插件后通过 :h syntastic查看原文档

简介
syntastic是vim下的一个代码语法检查插件, 实现原理是通过外部命令做语法检查，并把结果显示到vim中. 可是设置为保存文件的时候自动做语法检查.

syntastic 由两部分组成.

语法检查插件. 配合外部命令完成特定文件特定命令的语法检查
核心部分. 调度语法插件，并输出检查结果.
快速起步
安装教程参见项目文档.

使用方式如下:

:SyntasticInfo 显示当前的状态(激活还是禁用)/可用的checkers.
:SyntasticCheck 手动调用语法检查.默认错误信息不会输出到 quickfix
:Errors 错误输出到 quickfix, 并拉起errors窗口.
:lclose关闭错误窗口, 但是不会清空错误. :SyntasticReset 清空错误。
:SyntasticToggleMode 在激活禁用模式间切换.
使用使用 :lnext :lprevious 做错误间跳转，不需要跳到 quickfix 窗口
默认的配置并不好用， 可以参考下面的配置:

# 每次自动调用 :SyntasticSetLocList, 将错误覆盖 **quickfix**
let g:syntastic_always_populate_loc_list = 1
# 自动拉起/关闭错误窗口, 不需要手动调用 :Errors
let g:syntastic_auto_loc_list = 1
# 打开文件的时候做检查
let g:syntastic_check_on_open = 1
# 每次保存的时候做检查
let g:syntastic_check_on_wq = 1
支持的特性
statusline flag. 可以通过配置定制vim状态栏来显示syntastic相关信息.
set statusline+=%{SyntasticStatuslineFlag()}
error sign. 可以在vim行号左边显示一个错误标记，标记可配置.
" 配置error-sign
let g:syntastic_error_symbol = 'EE'
let g:syntastic_style_error_symbol = 'E>'
let g:syntastic_warning_symbol = 'WW'
let g:syntastic_style_warning_symbol = 'W>'
错误信息高亮(需要plugin check支持)
合并错误， 可以配置多个语法检查插件，最终将多个检查结果合并输出.
" 需要如下配置
let g:syntastic_aggregate_errors = 1
过滤错误. 可以选择性让插件忽略一部分错误提示. 参见: 'syntastic_quiet_messages' 'syntastic_ignore-files' 'syntastic_<filetype>_<checker>_quiet_messages'
相关命令
Errors:	拉起 quick_fix 窗口显示错误信息.
SyntasticToggleMode:
 	切换当前插件状态. 激活/禁用
SyntasticCheck:	手动调用语法检查
SyntasticInfo:	列表当前状态和可用check
SyntasticReset:	清空错误信息
SyntasticSetLoclist:
 	手动将错误输出到quick-fix, 但是不会打开错误窗口.(基本用不到改命令)
对常用命令可以配置一个快捷键. 推荐同时配置 :Errors :lclose :lnext :lprev 命令快捷键.

全局配置
syntastic_check_on_open:
 	0/1, 打开文件时做语法检查, 默认 0
syntastic_check_on_wq:
 	0/1 报错时做语法检查, 默认 1
syntastic_aggregate_errors:
 	0/1 合并错误, 默认 0 如果0则顺序调用check, 如果莫个check报错, 则不在调用后续check. 如果1则调用所有check, 并合并结果.
syntastic_id_checkers:
 	0/1 输出错误来源. 默认1
syntastic_sort_aggregated_errors:
 	对输出做排序, 默认1
syntastic_echo_current_error:
 	在命令行显示当前行的错误信息. 默认1
syntastic_cursor_columns:
 	默认1, 设为0加速。
syntastic_enable_sign:
 	做行号左边显示错误标记. 默认1
syntastic_enable_balloons:
 	鼠标悬停时显示当前行错误信息. 默认1, 改为0
syntastic_enable_highlighting:
 	开启错误信息语法高亮, 默认1
syntastic_always_populate_loc_list:
 	不需要手动调用 :SyntasticSetTocList. 默认1
syntastic_auto_jump:
 	默认0
syntastic_auto_loc_list:
 	自动拉起关闭错误窗口. 0不自动. 1自动拉起关闭. 2 自动关闭，但不自动拉起. 3 自动拉起，但不自动关闭 默认2, 改为1
syntastic_ignore_file:
 	添加不想被检查的文件.
syntastic_filetype_map:
 	将非标准filetype映射到标准文件.
syntastic_mode_map:
 	配置每个filetype和全局默认默认
syntastic_quiet_messages:
 	设置要忽略的错误

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => DoxygenToolkit 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 目前为止已经定义了5个用途：
1. 快速生成许可注释，并且标签可以被修改；
2. 快速生成作者声明框架，标签可修改；
3. 快速为C/C++、Python函数或者类生成注释框架，此框架包含的元素有：@brief, @param(为每一个参数生成一个@param)和@return。标签文本和注释块的头和尾都可以修改（因此，你可以有自己的简介，如果你原义，加上一点成就）；
忽 略在#ifdef...#endif(C/C++)块中代码碎片。给块命名的时候一定要考虑到其功能。在所有文件中，所有有联系的块将会放在一个新的块 DOX_SKIP_BLOCK（或者用户定义的名称）。你需要使用当前的新块名更新你的doxygen配置文件中的PREDEFINED变量。而且你还需 要将ENABLE_PREPROCESSING设置为YES。
4. 快速生成一个注释集（开始或者结尾），标签可修改；
使用：
4.1 注释类型（C/C++/// 或者, Python：##和#）：
在vim中，默认C++注释为，但是如果你更喜欢使用///，只需要在你的配置文件.vimrc中添加如下语句：
let g:DoxygenToolkit_commentType="C++"。

4.2 许可：
在vim中，将光标放在将要写doxygen许可注释的那一行，然后，执行命令：DoxLic。这将会生成许可注释并将光标放置在刚才那一行之后。

4.3 作者： 

在vim中，将光标放在想要添加doxygen作者注释的地方。然后执行命令：DoxAuthor。这将会生成一个框架，如果没有为其设置变量则将光标放置在@author标签之后，或者放在在框架之后。

4.4 函数/类注释：
在vim中，将光标放置在函数头部那一行（或者函数的返回变量）或者类。然后执行命令：Dox。这将生成框架并且将光标放置在@brief标签后。

4.5 忽略代码片段（只有C/C++）：
在vim中，如果你想要忽略所有在块中的代码片段，类似：           #ifdef DEBUG ... #endif你只需要执行以下命令：DoxUndoc(DEBUG)!

4.6 组：
在vim中，执行命令：DoxBlock在后面的行中插入一个doxygen块。

限制：
1. 假设函数名（后面的左括号）至少在当前光标位置后的第三行；
2. 在注释块在写入之前不能再次更新；
3. 块分隔符（头部和尾部）只包含函数注释；
4. 假设已经使用了缩进；
5. 函数参数中得到注释还不支持；(像void foo(int bar ))
6. 定制输出脚本，在脚本文件中，在.vimrc中设置g: DoxygenToolkit_*变量：
举例说明，在我的.vimrc中包含：
let g:DoxygenToolkit_briefTag_pre="@Synopsis  " 
let g:DoxygenToolkit_paramTag_pre="@Param " 
let g:DoxygenToolkit_returnTag="@Returns   " 
let g:DoxygenToolkit_blockHeader="--------------------------------------------------------------------------" 
let g:DoxygenToolkit_blockFooter="----------------------------------------------------------------------------" 
let g:DoxygenToolkit_authorName="Mathias Lorente" 
let g:DoxygenToolkit_licenseTag="My own license"   <-- !!! Does not end with "\<enter>"

安装细节：
将DoxygenToolkit.vim拷贝至 '~/.vim/plugin' 目录。

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => unite 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"unite.vim config
call unite#filters#matcher_default#use(['matcher_fuzzy'])
call unite#filters#sorter_default#use(['sorter_rank'])
call unite#set_profile('files', 'smartcase', 1)

let g:unite_data_directory='~/.vim/.cache/unite'
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

function! s:unite_settings()
  nmap <buffer> Q <plug>(unite_exit)
  nmap <buffer> <esc> <plug>(unite_exit)
  imap <buffer> <esc> <plug>(unite_exit)
  imap <buffer> <C-j>   <Plug>(unite_select_next_line)
  imap <buffer> <C-k>   <Plug>(unite_select_previous_line)
endfunction
autocmd FileType unite call s:unite_settings()

nmap <space> [unite]
nnoremap [unite] <nop>

nnoremap <silent> [unite]<space> :<C-u>Unite -toggle -auto-resize -buffer-name=mixed file_mru file_rec/async buffer bookmark<cr><c-u>
nnoremap <silent> [unite]f :<C-u>Unite -toggle -auto-resize -buffer-name=files file_rec/async<cr><c-u>
nnoremap <silent> [unite]y :<C-u>Unite -buffer-name=yanks history/yank<cr>
nnoremap <silent> [unite]l :<C-u>Unite -auto-resize -buffer-name=line line<cr>
nnoremap <silent> [unite]b :<C-u>Unite -auto-resize -buffer-name=buffers buffer<cr>
nnoremap <silent> [unite]/ :<C-u>Unite -no-quit -buffer-name=search grep:.<cr>
nnoremap <silent> [unite]m :<C-u>Unite -auto-resize -buffer-name=mappings mapping<cr>
nnoremap <silent> [unite]s :<C-u>Unite -quick-match buffer<cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Unite 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
打開vim以後，進入command mode，有三種主要用法和說明：
:Unite file
「顯示出你呼叫這個檔案目錄下的所有檔案和資料夾」
:Unite file_rec
「顯示出你呼叫這個檔案目錄下的所有檔案和資料夾，還有所有底下的資料」
:Unite buffer
「顯示出目前暫存的所有檔案」
buffer可以和其他兩個和用，ex.
:Unite buffer file
或是
:Unite buffer file_rec
注意每個檔案或是資料夾前面都有個「-」，如果你按空白鍵的話他會變成「*」，代表他被選取了
那我們選取這幾個檔案要幹嘛呢？這時候在按「a」的話，就會顯示出一堆「actions」，代表可以對這些檔案做這些「actions」

Unite是什么？

Unite可以在一个项目中快速浏览文件。但是它不仅限于文件，其他任何可以列出的东西都可以很好的被显示和搜索。这个开放式的特性很可能是人们找到它的原因(原文：This open-ended nature is probably what people find confusing about it.)

Unite不局限于搜索文件或者缓冲区--它可以很容易的处理文件和缓冲区，甚至更多。其他Vim插件的作者可以通过Unite提供的API扩展它，以用来支持其他数据源。

用法

Unite命令采用的格式为:Unite source，其中"source"是buffer，file和file_rec其中之一。

buffer: 浏览当前打开的buffer列表
file: 浏览当前目录的文件列表
file_rec: 递归的列出当前目录的文件
当一个命令被使用，一个新的水平分割窗口会被打开。比如，命令:Unite file将会显示当前目录的文件列表。在这个窗口中，标准的Vim命令模式下的命令可以使用--你可以使用“j”和“k”浏览该列表，可以使用“/”来查询。如果你在一个文件上按下enter键，Unite将会打开它。如果光标是在一个目录上，Unite将会进入该目录，并且更新该文件列表。

模式

如果你在Unite窗口进入插入模式，光标将会移到该窗口的最上方，并显示“>”提示符。输入字符会搜索该列表--这里和FuzzyFinder相似。和常规vim一样，按<ESC>键可以退出插入模式回到命令模式。

命令模式和插入模式都有相应的快捷键映射。比如在命令模式下，当光标在一个文件上，按下a，Unite会显示一个可以操作该文件命令的列表。这个命令列表被称为actions，这个列表可以像Unite其他部分一样被搜索和调用。

actions可以组合通配符。如果输入:Unite file, 然后按下*将会标记所有文件，再输入a将会列出所有actions，最后选择above，Unite将会打开所有被标记的文件。

其他特性

Unite也支持其他操作和浏览文件的方式，比如, :UniteBookmarkAdd会添加一个文件到书签列表中。书签通过:Unite bookmark来搜索和操作。

Unite没有附带任何映射键，但是你可以很容易的添加。下面的设置会调用:Unite file 当按下“<Leader>f”：

nnoremap f :Unite file    ==>  应该是 nnoremap <leader>f :Unite file
如果你仅仅只是想让Unite的功能和ctrlp.vim或者FuzzyFinder相似，这样你可以通过下面的映射键来实现：

nnoremap f :Unite -start-insert file    ==>  应该是  nnoremap <leader>f :Unite -start-insert file
Unite可以使用选项参数，比如，“-start-insert”会引起Unite打开提示窗口，在该窗口输入将会引起Unite搜索文件。

在VIM里，如果你不确定<Leader>是那个键，可以通过":help <Leader>"来查看。它一般是命名空间的快捷键，所以你应该输入“\f”来调用上面的例子。

结论

希望该篇文章说明白了Unite的主要特性，我觉得Unite是个非常有趣和常用的vim插件--它没有试着去模仿GUI IDEs，但是工作方式和vim保持一致。我不确定我是否喜欢命令模式和插入模式类似的使用方式，但是肯定会感觉到很自然在使用Unite一段时间后

"ctrl f ctrl b 本来是翻页
"空格选中 再a，进action
"nnoremap <C-f> :Unite -start-insert file<CR>
"nnoremap <C-b> :Unite buffer<CR>
"nnoremap <Leader>ff :Unite file<CR>
nnoremap <leader>f :Unite -start-insert file<CR>
"unite.vim config
call unite#filters#matcher_default#use(['matcher_fuzzy'])
call unite#filters#sorter_default#use(['sorter_rank'])
call unite#set_profile('files', 'smartcase', 1)

"let g:unite_data_directory='~/.vim/.cache/unite'
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
nnoremap <leader>f :Unite -start-insert file
function! s:unite_settings()
  nmap <buffer> Q <plug>(unite_exit)
  nmap <buffer> <esc> <plug>(unite_exit)
  imap <buffer> <esc> <plug>(unite_exit)
  imap <buffer> <C-j>   <Plug>(unite_select_next_line)
  imap <buffer> <C-k>   <Plug>(unite_select_previous_line)
endfunction
autocmd FileType unite call s:unite_settings()

nmap <space> [unite]
nnoremap [unite] <nop>

nnoremap <silent> [unite]<space> :<C-u>Unite -toggle -auto-resize -buffer-name=mixed file_mru file_rec/async buffer bookmark<cr><c-u>
nnoremap <silent> [unite]f :<C-u>Unite -toggle -auto-resize -buffer-name=files file_rec/async<cr><c-u>
nnoremap <silent> [unite]y :<C-u>Unite -buffer-name=yanks history/yank<cr>
nnoremap <silent> [unite]l :<C-u>Unite -auto-resize -buffer-name=line line<cr>
nnoremap <silent> [unite]b :<C-u>Unite -auto-resize -buffer-name=buffers buffer<cr>
nnoremap <silent> [unite]/ :<C-u>Unite -no-quit -buffer-name=search grep:.<cr>
nnoremap <silent> [unite]m :<C-u>Unite -auto-resize -buffer-name=mappings mapping<cr>
nnoremap <silent> [unite]s :<C-u>Unite -quick-match buffer<cr>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Airline 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
":set guifont=*  调出字体设置
":set guifont    显示当前字体
"设置时，注意下划线代替空格，或者用\（转义字符）代替空格  =（等号）后面不能有空格

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Mark 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
USAGE:
<F1>            Turn on/update highlighting for all lines with markers
<F2>            Turn off highlighting for lines with markers
<SHIFT-F2> Erase all markers [a-z]
<F5>             Add a mark on the current line (and highlight)
<SHIFT-F5> Remove the mark on the current line

Then, just jump from one mark to the next using the classic [' and ]' jumps


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => vim-indent-guides 插件
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set cc=80 竖线分隔，第80列现实竖线
调整数块宽度除了更改size，还要运行命令
retab
这样才能把别人的tab制表符，跟本地设置的制表符统一起来
" 自适应不同语言的智能缩进
filetype indent on
" 将制表符扩展为空格
set expandtab
" 设置编辑时制表符占用空格数
set tabstop=4
" 设置格式化时制表符占用空格数
set shiftwidth=4
" 让 vim 把连续数量的空格视为一个制表符
set softtabstop=4
其中，注意下 expandtab、tabstop 与 shiftwidth、softtabstop、retab：

expandtab，把制表符转换为多个空格，具体空格数量参考 tabstop 和 shiftwidth 变量；

tabstop 与 shiftwidth 是有区别的。tabstop 指定我们在插入模式下输入一个制表符占据的空格数量，linux 内核编码规范建议是 8，看个人需要；shiftwidth 指定在进行缩进格式化源码时制表符占据的空格数。所谓缩进格式化，指的是通过 vim 命令由 vim 自动对源码进行缩进处理，比如其他人的代码不满足你的缩进要求，你就可以对其进行缩进格式化。缩进格式化，需要先选中指定行，要么键入 = 让 vim 对该行进行智能缩进格式化，要么按需键入多次 < 或 > 手工缩进格式化；

softtabstop，如何处理连续多个空格。因为 expandtab 已经把制表符转换为空格，当你要删除制表符时你得连续删除多个空格，该就是告诉 vim 把连续数量的空格视为一个制表符，即，只删一个字符即可。通常应将这tabstop、shiftwidth、softtabstop 三个变量设置为相同值；

另外，你总会阅读其他人的代码吧，他们对制表符定义规则与你不同，这时你可以手工执行 vim 的 retab 命令，让 vim 按上述规则重新处理制表符与空格关系。
以下这样也可以不用插件：
" 显示tab和空格
set list
" 设置tab和空格样式
set lcs=tab:\|\ ,nbsp:%,trail:-
" 设定行首tab为灰色
highlight LeaderTab guifg=#666666
" 匹配行首tab
match LeaderTab /^\t/

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => submodule 地址
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
sudo git submodule add https://github.com/vim-airline/vim-airline-themes.git bundle/vim-airline-themes
sudo git submodule add https://github.com/vim-scripts/bufexplorer.zip.git bundle/bufexplorer
sudo git submodule add https://github.com/vim-scripts/mru.vim.git bundle/mru.vim
sudo git submodule add -f  https://github.com/Shougo/vimshell.vim.git bundle/vimshell.vim
sudo git submodule add -f  https://github.com/Shougo/vimproc.vim.git bundle/vimproc.vim
sudo git submodule add https://github.com/nathanaelkane/vim-indent-guides.git bundle/vim-indentt-guides.vim
sudo git submodule add https://github.com/vim-scripts/a.vim.git bundle/a.vim
sudo git submodule add https://github.com/kshenoy/vim-signature.git bundle/signature.vim
sudo git submodule add https://github.com/vim-scripts/vimprj.git bundle/vimprj.vim
sudo git submodule add https://github.com/vim-scripts/DfrankUtil.git bundle/DfrankUtil.vim
sudo git submodule add https://github.com/vim-scripts/indexer.tar.gz.git bundle/indexer.vim
sudo git submodule add https://github.com/scrooloose/nerdcommenter.git bundle/nerdcommenter.vim
sudo git submodule add https://github.com/derekwyatt/vim-fswitch.git bundle/vim-fswitch.vim
sudo git submodule add https://github.com/derekwyatt/vim-protodef.git bundle/vim-protodef.vim
sudo git submodule add https://github.com/easymotion/vim-easymotion.git bundle/vim-easymotion
sudo git submodule add https://github.com/fholgado/minibufexpl.vim.git bundle/minibufexpl.vim
sudo git submodule add https://github.com/vim-scripts/YankRing.vim.git bundle/YankRing.vim
sudo git submodule add https://github.com/vim-scripts/mru.vim.git bundle/mru.vim
sudo git submodule add https://github.com/vim-scripts/DoxygenToolkit.vim.git bundle/DoxygenToolkit.vim
sudo git submodule add https://github.com/Shougo/unite.vim.git bundle/unite.vim
sudo git submodule add https://github.com/mbbill/undotree.git bundle/undotree.vim
sudo git submodule add https://github.com/mhinz/vim-signify.git bundle/vim-signify.vim
sudo git submodule add https://github.com/vim-ctrlspace/vim-ctrlspace.git bundle/vim-ctrlspace.vim
sudo git submodule add https://github.com/vim-scripts/BOOKMARKS--Mark-and-Highlight-Full-Lines.git bundle/Mark-and-Highlight.vim
sudo git submodule add https://github.com/Raimondi/delimitMate.git bundle/delimitMate.vim

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => tmux命令
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
如果tmux启动直接显示exit
解决办法：
I had this same problem. It was caused by having set-option -g default-command "reattach-to-user-namespace -l zsh" in my .tmux.conf without having reattach-to-user-namespace installed.

The fix was to install "reattach-to-user-namespace" via Homebrew (brew install reattach-to-user-namespace)
是说config里配置了reattach....但是没有安装reattach，安装就可以了
如果显示mousexx option 有问题
http://www.davidverhasselt.com/enable-mouse-support-in-tmux-on-os-x/ 这个网站有介绍
基本是先改配置文件
set -g mouse-utf8 on
set -g mouse on
bind -n WheelUpPane   select-pane -t= \; copy-mode -e \; send-keys -M
bind -n WheelDownPane select-pane -t= \;                 send-keys -M
#setw -g mode-mouse on
#set -g mouse-select-pane on
#set -g mouse-resize-pane on
#set -g mouse-select-window on
改成上面，然后
brew cask install easysimbl 装这个
接着下载这个并且安装
 Download .dmg file here: https://bitheap.org/mouseterm/

运行tmux报
zsh compinit: insecure directories, run compaudit for list.
Ignore insecure directories and continue [y] or abort compinit [n]?
错误时，进入到/usr/local/Cellar/zsh/5.2/share/zsh目录下，执行以下命令，第一二行的cd，按各自目录情况决定
$ cd /usr/local/share/
$ cd /usr/local/Cellar/zsh/5.2/share/zsh
$ sudo chmod -R 755 zsh
$ sudo chown -R root:staff zsh

tmux
查看已有session

tmux ls

关闭session
mux kill-session -t

进入tmux后

默认快捷键前缀为Ctrl+b，可以通过配置文件来修改

从session中断开

C-b d
给session改名字（下次tmux ls看到的就不是数字了）：

创建新窗口

C-b c
 删除当前窗口

C-b x   #删除一个窗口中一个窗格（如果只有一个窗格则和删除窗口一样)
C-b &   #删除一个窗口（所有分割的窗格都会被关闭）
 分割窗口

C-b %  #左右分
C-b "  #上下分
 窗口的跳转

C-b n  #下一个窗口
C-b p  #上一个窗口
C-b l  #刚刚访问过的那个（last）窗口

类似各种平铺式窗口管理器，tmux使用键盘操作，常用快捷键包括：

Ctrl+b	激活控制台；此时以下按键生效
系统操作	
?	列出所有快捷键；按q返回
d	脱离当前会话；这样可以暂时返回Shell界面，输入tmux attach能够重新进入之前的会话
D	选择要脱离的会话；在同时开启了多个会话时使用
Ctrl+z	挂起当前会话
r	强制重绘未脱离的会话
s	选择并切换会话；在同时开启了多个会话时使用
:	进入命令行模式；此时可以输入支持的命令，例如kill-server可以关闭服务器
[	进入复制模式；此时的操作与vi/emacs相同，按q/Esc退出
~	列出提示信息缓存；其中包含了之前tmux返回的各种提示信息
窗口操作	
c	创建新窗口
&	关闭当前窗口
数字键	切换至指定窗口
p	切换至上一窗口
n	切换至下一窗口
l	在前后两个窗口间互相切换
w	通过窗口列表切换窗口
,	重命名当前窗口；这样便于识别
.	修改当前窗口编号；相当于窗口重新排序
f	在所有窗口中查找指定文本
面板操作	
“	将当前面板平分为上下两块
%	将当前面板平分为左右两块
x	关闭当前面板
!	将当前面板置于新窗口；即新建一个窗口，其中仅包含当前面板
Ctrl+方向键	以1个单元格为单位移动边缘以调整当前面板大小
Alt+方向键	以5个单元格为单位移动边缘以调整当前面板大小
Space	在预置的面板布局中循环切换；依次包括even-horizontal、even-vertical、main-horizontal、main-vertical、tiled
q	显示面板编号
o	在当前窗口中选择下一面板
方向键	移动光标以选择面板
{	向前置换当前面板
}	向后置换当前面板
Alt+o	逆时针旋转当前窗口的面板
Ctrl+o	顺时针旋转当前窗口的面板



"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => iTerm2 配色方案
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
iTerm2 配色方案
http://iterm2colorschemes.com/
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => zsh
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
https://coderwall.com/p/sun7za/mac-os-x-oh-my-zsh-theme-on-iterm2
https://github.com/jeremyFreeAgent/oh-my-zsh-powerline-theme
# ducknorris custom theme
# FreeAgent puts the powerline style in zsh !

if [ "$POWERLINE_DATE_FORMAT" = "" ]; then
  POWERLINE_DATE_FORMAT=%D{%Y-%m-%d}
fi

if [ "$POWERLINE_RIGHT_B" = "" ]; then
  POWERLINE_RIGHT_B=%D{%H:%M:%S}
elif [ "$POWERLINE_RIGHT_B" = "none" ]; then
  POWERLINE_RIGHT_B=""
fi

if [ "$POWERLINE_RIGHT_A" = "mixed" ]; then
  POWERLINE_RIGHT_A=%(?."$POWERLINE_DATE_FORMAT".%F{red}✘ %?)
elif [ "$POWERLINE_RIGHT_A" = "exit-status" ]; then
  POWERLINE_RIGHT_A=%(?.%F{green}✔ %?.%F{red}✘ %?)
elif [ "$POWERLINE_RIGHT_A" = "date" ]; then
  POWERLINE_RIGHT_A="$POWERLINE_DATE_FORMAT"
fi

if [ "$POWERLINE_HIDE_USER_NAME" = "" ] && [ "$POWERLINE_HIDE_HOST_NAME" = "" ]; then
    POWERLINE_USER_NAME="%n@"'%M'
elif [ "$POWERLINE_HIDE_USER_NAME" != "" ] && [ "$POWERLINE_HIDE_HOST_NAME" = "" ]; then
    POWERLINE_USER_NAME="@%M"
elif [ "$POWERLINE_HIDE_USER_NAME" = "" ] && [ "$POWERLINE_HIDE_HOST_NAME" != "" ]; then
    POWERLINE_USER_NAME="%n"
else
    POWERLINE_USER_NAME=""
fi

POWERLINE_CURRENT_PATH="%d"

if [ "$POWERLINE_FULL_CURRENT_PATH" = "" ]; then
  POWERLINE_CURRENT_PATH="%1~"
fi

if [ "$POWERLINE_GIT_CLEAN" = "" ]; then
  POWERLINE_GIT_CLEAN="✔"
fi

if [ "$POWERLINE_GIT_DIRTY" = "" ]; then
  POWERLINE_GIT_DIRTY="✘"
fi

if [ "$POWERLINE_GIT_ADDED" = "" ]; then
  POWERLINE_GIT_ADDED="%F{green}✚%F{black}"
fi

if [ "$POWERLINE_GIT_MODIFIED" = "" ]; then
  POWERLINE_GIT_MODIFIED="%F{blue}✹%F{black}"
fi

if [ "$POWERLINE_GIT_DELETED" = "" ]; then
  POWERLINE_GIT_DELETED="%F{red}✖%F{black}"
fi

if [ "$POWERLINE_GIT_UNTRACKED" = "" ]; then
  POWERLINE_GIT_UNTRACKED="%F{yellow}✭%F{black}"
fi

if [ "$POWERLINE_GIT_RENAMED" = "" ]; then
  POWERLINE_GIT_RENAMED="➜"
fi

if [ "$POWERLINE_GIT_UNMERGED" = "" ]; then
  POWERLINE_GIT_UNMERGED="═"
fi

ZSH_THEME_GIT_PROMPT_PREFIX=" \ue0a0 "
ZSH_THEME_GIT_PROMPT_SUFFIX=""
ZSH_THEME_GIT_PROMPT_DIRTY=" $POWERLINE_GIT_DIRTY"
ZSH_THEME_GIT_PROMPT_CLEAN=" $POWERLINE_GIT_CLEAN"

ZSH_THEME_GIT_PROMPT_ADDED=" $POWERLINE_GIT_ADDED"
ZSH_THEME_GIT_PROMPT_MODIFIED=" $POWERLINE_GIT_MODIFIED"
ZSH_THEME_GIT_PROMPT_DELETED=" $POWERLINE_GIT_DELETED"
ZSH_THEME_GIT_PROMPT_UNTRACKED=" $POWERLINE_GIT_UNTRACKED"
ZSH_THEME_GIT_PROMPT_RENAMED=" $POWERLINE_GIT_RENAMED"
ZSH_THEME_GIT_PROMPT_UNMERGED=" $POWERLINE_GIT_UNMERGED"
ZSH_THEME_GIT_PROMPT_AHEAD=" ⬆"
ZSH_THEME_GIT_PROMPT_BEHIND=" ⬇"
ZSH_THEME_GIT_PROMPT_DIVERGED=" ⬍"

if [ "$POWERLINE_SHOW_GIT_ON_RIGHT" = "" ]; then
    if [ "$POWERLINE_HIDE_GIT_PROMPT_STATUS" = "" ]; then
        POWERLINE_GIT_INFO_LEFT=" %F{blue}%K{white}"$'\ue0b0'"%F{white}%F{black}%K{white}"$'$(git_prompt_info)$(git_prompt_status)%F{white}'
    else
        POWERLINE_GIT_INFO_LEFT=" %F{blue}%K{white}"$'\ue0b0'"%F{white}%F{black}%K{white}"$'$(git_prompt_info)%F{white}'
    fi
    POWERLINE_GIT_INFO_RIGHT=""
else
    POWERLINE_GIT_INFO_LEFT=""
    POWERLINE_GIT_INFO_RIGHT="%F{white}"$'\ue0b2'"%F{black}%K{white}"$'$(git_prompt_info)'" %K{white}"
fi

if [ $(id -u) -eq 0 ]; then
    POWERLINE_SEC1_BG=%K{red}
    POWERLINE_SEC1_FG=%F{red}
else
    POWERLINE_SEC1_BG=%K{green}
    POWERLINE_SEC1_FG=%F{green}
fi
POWERLINE_SEC1_TXT=%F{black}
if [ "$POWERLINE_DETECT_SSH" != "" ]; then
  if [ -n "$SSH_CLIENT" ]; then
    POWERLINE_SEC1_BG=%K{red}
    POWERLINE_SEC1_FG=%F{red}
    POWERLINE_SEC1_TXT=%F{white}
  fi
fi
PROMPT="$POWERLINE_SEC1_BG$POWERLINE_SEC1_TXT $POWERLINE_USER_NAME %k%f$POWERLINE_SEC1_FG%K{blue}"$'\ue0b0'"%k%f%F{white}%K{blue} "$POWERLINE_CURRENT_PATH"%F{blue}"$POWERLINE_GIT_INFO_LEFT" %k"$'\ue0b0'"%f "

if [ "$POWERLINE_NO_BLANK_LINE" = "" ]; then
    PROMPT="
"$PROMPT
fi

if [ "$POWERLINE_DISABLE_RPROMPT" = "" ]; then
    if [ "$POWERLINE_RIGHT_A" = "" ]; then
        RPROMPT="$POWERLINE_GIT_INFO_RIGHT%F{white}"$'\ue0b2'"%k%F{black}%K{white} $POWERLINE_RIGHT_B %f%k"
    elif [ "$POWERLINE_RIGHT_B" = "" ]; then
        RPROMPT="$POWERLINE_GIT_INFO_RIGHT%F{white}"$'\ue0b2'"%k%F{240}%K{white} $POWERLINE_RIGHT_A %f%k"
    else
        RPROMPT="$POWERLINE_GIT_INFO_RIGHT%F{white}"$'\ue0b2'"%k%F{black}%K{white} $POWERLINE_RIGHT_B %f%F{240}"$'\ue0b2'"%f%k%K{240}%F{255} $POWERLINE_RIGHT_A %f%k"
    fi
fi

#上面的放到主题里面去
#And finally .zshrc
底下的放到zshrc里面

# Path to your oh-my-zsh configuration.
ZSH=$HOME/.oh-my-zsh

# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
ZSH_THEME="ducknorris"

POWERLINE_DETECT_SSH="true"
POWERLINE_GIT_CLEAN="✔"
POWERLINE_GIT_DIRTY="✘"
POWERLINE_GIT_ADDED="%F{green}✚%F{black}"
POWERLINE_GIT_MODIFIED="%F{blue}✹%F{black}"
POWERLINE_GIT_DELETED="%F{red}✖%F{black}"
POWERLINE_GIT_UNTRACKED="%F{yellow}✭%F{black}"
POWERLINE_GIT_RENAMED="➜"
POWERLINE_GIT_UNMERGED="═"

alias zshconfig="s ~/.zshrc"
alias ohmyzsh="s ~/.oh-my-zsh"

alias my="/usr/local/mysql/bin/mysql"
alias c="/usr/local/bin/cloc"
alias s="/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl"
alias p="/usr/local/Cellar/python/2.7.5/bin/python"

alias gpall="git pushall"

COMPLETION_WAITING_DOTS="true"

plugins=(git brew rails3 git-flow capistrano zeus)

source $ZSH/oh-my-zsh.sh

export PATH=/Users/ducky/.rvm/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin

if [[ -s "/Users/ducky/.rvm/scripts/rvm" ]] ; then source "/Users/ducky/.rvm/scripts/rvm" ; fi
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => python相关
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Pip and setuptools have been installed. To update them
  pip install --upgrade pip setuptools

You can install Python packages with
  pip install <package>

They will install into the site-package directory
  /usr/local/lib/python2.7/site-packages

See: https://github.com/Homebrew/homebrew/blob/master/share/doc/homebrew/Homebrew-and-Python.md

.app bundles were installed.
Run `brew linkapps python` to symlink these to /Applications.
==> Summary
🍺  /usr/local/Cellar/python/2.7.11: 4,886 files, 66.0M
 BLUE@B1_CYJK_3952_4  phone_h265  pip install --upgrade pip setuptools                                                                                                                22:45:13  08-04
Collecting pip
  Using cached pip-8.1.1-py2.py3-none-any.whl
Collecting setuptools
  Downloading setuptools-20.6.7-py2.py3-none-any.whl (508kB)
    100% |████████████████████████████████| 512kB 17kB/s
Installing collected packages: pip, setuptools
  Found existing installation: pip 8.0.2
    Uninstalling pip-8.0.2:
Exception:
Traceback (most recent call last):
  File "/usr/local/lib/python2.7/site-packages/pip/basecommand.py", line 209, in main
    status = self.run(options, args)
  File "/usr/local/lib/python2.7/site-packages/pip/commands/install.py", line 317, in run
    prefix=options.prefix_path,
  File "/usr/local/lib/python2.7/site-packages/pip/req/req_set.py", line 725, in install
    requirement.uninstall(auto_confirm=True)
  File "/usr/local/lib/python2.7/site-packages/pip/req/req_install.py", line 752, in uninstall
    paths_to_remove.remove(auto_confirm)
  File "/usr/local/lib/python2.7/site-packages/pip/req/req_uninstall.py", line 115, in remove
    renames(path, new_path)
  File "/usr/local/lib/python2.7/site-packages/pip/utils/__init__.py", line 266, in renames
    shutil.move(old, new)
  File "/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/lib/python2.7/shutil.py", line 300, in move
    rmtree(src)
  File "/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/lib/python2.7/shutil.py", line 252, in rmtree
    onerror(os.remove, fullname, sys.exc_info())
  File "/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/lib/python2.7/shutil.py", line 250, in rmtree
    os.remove(fullname)
OSError: [Errno 13] Permission denied: '/usr/local/lib/python2.7/site-packages/pip/__init__.py'
You are using pip version 8.0.2, however version 8.1.1 is available.
You should consider upgrading via the 'pip install --upgrade pip' command.
 BLUE@B1_CYJK_3952_4  phone_h265  sudo pip install --upgrade pip setuptools                                                                                                           22:46:36  08-04
The directory '/Users/BLUE/Library/Caches/pip/http' or its parent directory is not owned by the current user and the cache has been disabled. Please check the permissions and owner of that directory. If executing pip with sudo, you may want sudo's -H flag.
The directory '/Users/BLUE/Library/Caches/pip' or its parent directory is not owned by the current user and caching wheels has been disabled. check the permissions and owner of that directory. If executing pip with sudo, you may want sudo's -H flag.
Collecting pip
  Downloading pip-8.1.1-py2.py3-none-any.whl (1.2MB)
    100% |████████████████████████████████| 1.2MB 44kB/s
Collecting setuptools
  Downloading setuptools-20.6.7-py2.py3-none-any.whl (508kB)
    100% |████████████████████████████████| 512kB 40kB/s
Installing collected packages: pip, setuptools
  Found existing installation: pip 8.0.2
    Uninstalling pip-8.0.2:
      Successfully uninstalled pip-8.0.2
  Found existing installation: setuptools 19.4
    Uninstalling setuptools-19.4:
      Successfully uninstalled setuptools-19.4
Successfully installed pip-8.1.1 setuptools-20.6.7
 BLUE@B1_CYJK_3952_4  phone_h265 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => tmux命令
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => tmux命令
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


























