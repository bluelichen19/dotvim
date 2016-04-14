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
"    -> sublimeText相关 
"    -> tmux命令
"    -> SYNTAX 注解 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => 键盘映射
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
:verbose map <D-Up> 查看是否有冲突，后面的<D-Up> 意思查看Command+↑是否被占用
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

本命令列出所有的语法项目:

    :sy[ntax] [list]

要显示单个语法组的所有语法项目:

    :sy[ntax] list {group-name}

要列出单个簇的所有语法组:                                      

    :sy[ntax] list @{cluster-name}
有三种类型的高亮组:
- 用于特定语言的。这些组的名字以该语言的名字开始。它们中很多没有属性，而是链接
  到第二种类型的组。
- 用于所有语法语言的。
- 用于 'highlight' 选项的。
                                                        *hitest.vim*
用这个命令，你可以看到当前激活的所有组:
    :so $VIMRUNTIME/syntax/hitest.vim
它会打开一个新窗口，其中包含所有的高亮组名，以它们本身的颜色显示。

                                                *:colo* *:colorscheme* *E185*
:colo[rscheme]          输出当前激活的色彩方案名。基本上等同
                                :echo g:colors_name
                        如果 g:colors_name 没有定义 :colo 会输出 "default"。如
                        果编译时没有带 |+eval| 特性，输出 "unknown"。

:colo[rscheme] {name}   载入色彩方案 {name}。它会在 'runtimepath' 里搜索
                        "colors/{name}.vim"，载入第一个找到的文件。
                        要看到当前激活的色彩方案的名字:
                                :colo
                        该名字也保存在 g:colors_name 变量里。
                        它不能递归调用，所以你不能在色彩方案脚本里使用
                        ":colorscheme"。
                        色彩方案载入后，激活 |ColorScheme| 自动命令事件。关于
                        如何编写色彩方案文件的信息:
                                :edit $VIMRUNTIME/colors/README.txt

:hi[ghlight]            列出当前所有的有属性设置的高亮组。

:hi[ghlight] {group-name}
                        列出一个高亮组。

:hi[ghlight] clear      复位高亮设置为缺省值。删除所有用户增加的组的高亮属性。
                        用当前的 'background' 的值来决定所使用的缺省颜色。

:hi[ghlight] clear {group-name}
:hi[ghlight] {group-name} NONE
                        屏蔽一个高亮组的所有高亮设置。并_不_复原缺省的颜色。

:hi[ghlight] [default] {group-name} {key}={arg} ..
                        增加高亮组，或者更改已有的组高亮设置。
                        |highlight-args| 说明 {key}={arg} 的参数。
                        |:highlight-default| 说明可选的 [default] 参数。

通常，在启动时加入高亮组。它设置高亮的缺省值。在这之后，你可以使用附加的
highlight 命令来修改你希望设置为非缺省值的参数。也可以用 "NONE" 来撤销某个值并
恢复缺省的值。

修改颜色的简单方式是 |:colorscheme| 命令。它载入一个文件，里面包含了这样的
":highlight" 命令:

   :hi Comment  gui=bold

注意 所有没有包含在内的设置都保持原样，只使用指定的字段，从而和以前的设置进行
了合并。所以实际结果就像用了下面这样的一条命令:
   :hi Comment  term=bold ctermfg=Cyan guifg=#80a0ff gui=bold

                                                        *:highlight-verbose*
如果列出高亮组时 'verbose' 非零，同时列出高亮组最近在哪里设置。例如:
        :verbose hi Comment
        Comment        xxx term=bold ctermfg=4 guifg=Blue 
           Last set from /home/mool/vim/vim7/runtime/syntax/syncolor.vim 

如果使用了 ":hi clear"，那么列出缺省值的同时提到使用该命令的脚本。详见
|:verbose-cmd|。

                                        *highlight-args* *E416* *E417* *E423*
用于高亮，有三种类型的终端:
term    普通的终端 (vt100、xterm)
cterm   色彩终端 (MS-DOS 控制台、color-xterm，带有 "Co" termcap 项目的终端)
gui     GUI

每种类型可以分别设置高亮属性。这样，单个语法文件就可用于所有的终端，并使用每个
终端最优的高亮设置。

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
 当出现类似以下问题，运行submodule foreach --recursive git checkout .
git subproject commit xxxxxxxxxxxxxxxxxxxxx -dirty
-Subproject commit 8c75e65b647238febd0257658b150f717a136359
+Subproject commit 8c75e65b647238febd0257658b150f717a136359-dirty
不知道如何操作出现的 dirty , 可印象中又什么都修改过

解决办法, 进入提示的那个文件夹中 git checkout .

摘录出来的部分英文回复如下:

As mentioned in Mark Longair's blog post Git Submodules Explained,

Versions 1.7.0 and later of git contain an annoying change in the behavior of git submodule.
Submodules are now regarded as dirty if they have any modified files or untracked files, whereas previously it would only be the case if HEAD in the submodule pointed to the wrong commit.

The meaning of the plus sign (+) in the output of git submodule has changed, and the first time that you come across this it takes a little while to figure out what’s going wrong, for example by looking through changelogs or using git bisect on git.git to find the change. It would have been much kinder to users to introduce a different symbol for “at the specified version, but dirty”.

You can fix it by:

either committing or undoing the changes/evolutions within each of your submodules, before going back to the parent repo (where the diff shouldn't report "dirty" files anymore). To undo all changes to your submodule just cd into the root directory of your submodule and do git checkout .

dotnetCarpenter comments that you can do a: git submodule foreach --recursive git checkout .

or add --ignore-submodules to your git diff, to temporarily ignore those "dirty" submodules.

New in Git version 1.7.2
As Noam comments below, this question mentions that, since git version 1.7.2, you can ignore the dirty submodules with:

git status --ignore-submodules=dirty

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

find . -name "*.cpp" -type f -exec sh -c "iconv -c -f CP936 -t UTF8 {} > {}.cpputf8" \;
find . -name "*.c" -type f -exec sh -c "iconv -c -f CP936 -t UTF8 {} > {}.cutf8" \;
find . -name "*.h" -type f -exec sh -c "iconv -c  -f CP936 -t UTF8 {} > {}.hutf8" \;
find . -name "*.cpp" -type f | xargs rm -rf                             
find . -name "*.c" -type f | xargs rm -rf                       
find . -name "*.h" -type f | xargs rm -rf                               
find . -name "*.cutf8" -type f | sed 's/.cutf8$//' | xargs -I {} mv {}.cutf8 {}
find . -name "*.cpputf8" -type f | sed 's/.cpputf8$//' | xargs -I {} mv {}.cpputf8 {}
find . -name "*.hutf8" -type f | sed 's/.hutf8$//' | xargs -I {} mv {}.hutf8 {}

合并两条语句
find . -name "*.cpp" -type f | xargs rm -rf;find . -name "*.c" -type f | xargs rm -rf;find . -name "*.h" -type f | xargs rm -rf
find . -name "*.cutf8" -type f | sed 's/.cutf8$//' | xargs -I {} mv {}.cutf8 {};find . -name "*.cpputf8" -type f | sed 's/.cpputf8$//' | xargs -I {} mv {}.cpputf8 {};find . -name "*.hutf8" -type f | sed 's/.hutf8$//' | xargs -I {} mv {}.hutf8 {}

另一种工具，可以批量直接转换
find . -name "*.cpp" -type f |xargs enca -L zh_CN -x UTF-8;find . -name "*.h" -type f |xargs enca -L zh_CN -x UTF-8;find . -name "*.c" -type f |xargs enca -L zh_CN -x UTF-8

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

下面是修改hostname和主机名字
虽然mac不如ubuntu感觉open,但是系统感觉还是挺好用的.用了小半年了,积累了几个不可缺少的经验,记录一下(因为头两周用的时候又忘记了.).
 
1.修改机器名
 mac安装完成以后会默认将你的机器设成"rainbird's Macbook Pro"之类的名字.这个本身看着就不爽,如果这台机器是别人先用你再用的话,就想把它改掉了.如果你想改计算机名的话,直接去"系统设置"->"共享"里改计算机名(Computer Name)就好了.这样大家在网络邻居里看到的你的名字就可以了.
对于大多数用户来说到这里就完事了.但是对于系统管理员来说,每次打开终端的时候发现还有一个"rainbird's Macbook Pro"的东东在那里还是感觉很不爽.估计这个想改的人少,笔者费了九牛二虎之力才在mac的一个论坛的不起眼的小角落翻出来修改它的命令:
sudo scutil --set HostName rainbird-desk
再新开一个终端,是不是感觉很顺眼了?
顺便说一下,命令行改那个共享名的方法:
sudo scutil --set ComputerName newName

观察一下这两个指令你就会发现,苹果真讲究,一个名字还分计算机名和主机名.

2.修改提示符

对于系统管理员来说,天天用终端,可是由于centos先入为主的观念,对于后来的ubuntu和mac的命令提示符感觉很不爽,咋办呢?好办,两者的修改方法一样:
vi ~/.profile (有就修改,没有就新建)
export PS1="[\u@\h \W]\$ "
保存以后source ~/.profile.是不是看着又很顺眼了?
 3.隐藏显示文件或文件夹
[rainbird@rainbird-desk ~]$ chflags hidden php
[rainbird@rainbird-desk ~]$ chflags nohidden php
 这样就可以在finder中隐藏显示home目录下的php文件夹了.很好使,当然了,在终端下ls还是马上现原形的.不过可以忽悠一下小朋友.

下面是修改命令提示符
定制你的 zsh 命令提示符

最早从 LinuxToy 那里看到有关 zsh 的介绍 ，因为牠强力的功能而喜欢上了这个玩意儿。 自然，用的命令提示符也是那篇文章的作者 Kardinal 提供的那个颇炫的命令提示符。 可惜，那个命令提示符不能在控制台下使用，与此同时，linux 摸久了，也开始觉得这个东西太过于花俏。 自然，就想自己定制一个。可惜官方只有英文文档，所以只好硬着头皮用我烂得可以的英文边猜边翻译了…… 这篇文章的由来就是如此。 先发出我折腾了 N 久的成果吧： 图片在这里：http://min.us/mg06HbxXF6t21 不知道为什么外链出来的图片大小出了问题…… 代码在这里：

PROMPT='%B%{[32m%}%n%(?. . %{[31m%}%? )%{[m%}> %{[1;34m%}%~ %{[m%}%# %b'
再把翻译的文章贴出来，文中有一部分可能没有翻译，那个也请见谅…… 单单翻译了这么些内容，我已经花去了 3 个小时了……
有关提示符的色彩

zsh里着色需要在转义字符/普通字符前填入：

%{^[[<色彩编号>m%}
其中 '^['需要 Vim 在插入模式下按下 Ctrl+v Esc 才能输入，如果没有输入色彩的编号，那么就是默认色彩
色彩编号如下：

Black 0;30  Dark Gray 1;30
Blue 0;34   Light Blue 1;34
Green 0;32  Light Green 1;32
Cyan 0;36   Light Cyan 1;36
Red 0;31    Light Red 1;31
Purple 0;35 Light Purple 1;35
Brown 0;33  Yellow 1;33
Light Gray 1;37 White 1;37
提示符介绍

Special characters

%%  一个'%'
#%) 一个')'
Login information

%y  当前的tty名
%l  当前的tty名，如 pts/1
%M  完整主机名
%m  主机名（在第一个句号之前截断）
%n  当前用户名
Shell state

%. %c %C    前两个显示相对路径的当前文件夹名，最后一个是绝对路径（也就是说，前两个在家目录下显示'~'，最后那个显示你的用户名），'%'后的数字表示显示几层路径
%N  zsh 正在执行的脚本/函数名。如果'%'后跟了数字，似乎还有其他作用
%L  当前shell的层数，可以参考《盗梦空间》的层数
%j  当前正在进行的工作数量
%i  与%!类似：The line number currently being executed in the script, sourced file, or shell function given by %N. This is most useful for debugging as part of $PS4.
%!  显示当前历史事件号码（也就是打开shell后第几条命令）
%/ %d   显示当前工作路径（$pwd）。如果'％'后面是一个整数，它指定显示路径的元件的数量;没有数字就显示整个路径。一个负整数就是指定主目录，即％-1d代表第一部分
%~  目前的工作目录相对于～的相对路径
%_  The status of the parser, i.e. the shell constructs (like if' andfor') that have been started on the command line. If given an integer number that many strings will be printed; zero or negative or no integer means print as many as there are. This is most useful in prompts PS2 for continuation lines and PS4 for debugging with the XTRACE option; in the latter case it will also work non-interactively.
%?  返回最后命令的执行结果的代码
%#  用户组，#（普通用户）/%（超级用户）
Date and time

%D{}    格式化日期，内容在下：
%f %e ：当月日期 (如果是个位数的话，第二个比第一个多一个占位符（一个空格）
%K %k ：24小时制，第二个比第一个多占位符
%L %l ：12小时制，第二个比第一个多占位符
%W  系统日期 (月-日-年)
%w  系统日期 (周几 日期)
%D  系统日期（年-月-日）
%T  系统时间（时：分），24小时制
%t %@   系统时间，12小时制
%*  系统时间（时：分：秒）
Visual effects

%B(%b)  开始到结束使用粗体打印
%U(%u)  开始到结束使用下划线打印
%S(%s)  开始到结束使用突出模式打印
%{..%}  可以输入一些转义字符，花括号里的内容不会改变光标位置，花括号可以嵌套
%E  清空一行
Conditional substrings

%v ：获取 psvar 数组的第一个值，’%‘后是什么数字就返回第几个值，负数就返回倒数过去的值 %(x.true-text.false-text) ： 这是一个判断式，判断 x 的真假，真则输出 true-text ，否则输出 false-text 左侧括号前后可以插入一个正数n，如果是负数的话就会被乘以 -1，n在下文会用到 x 有以下内容：
!   是否是 root 权限
#   当前进程的UID是否等于n
g   当前进程的有效GID是否等于n
?   最后命令的返回值是否等于n
_   True if at least n Shell constructs were started
C / 当前的绝对路径是否至少有n个元素
c . ~   True if the current path, with prefix replacement, has at least n elements.
D   当前月份是否等于n，1月等于0
d   当前日期是否等于n
j   当前作业数是否等于n
L   当前shell层数是否等于n
l   当前是否已经至少有n个字符已经打印
S   True if the SECONDS parameter is at least n.
T   当前小时是否等于n
t   当前的分钟是否等于n
v   当前 psvar 数组是否已经至少有n个元素
w   是否等于周n，周日是0
%string> %[xstring] Specifies truncation behaviour for the remainder of the prompt string. The >'. The numeric argument, which in the third form may appear immediately after the[', specifies the maximum permitted length of the various strings that can be displayed in the prompt. The string will be displayed in place of the truncated portion of any string; note this does not undergo prompt expansion.

The forms with <' truncate at the left of the string, and the forms with>' truncate at the right of the string. For example, if the current directory is /home/pike', the prompt%8<..<%/' will expand to ..e/pike'. In this string, the terminating character (<', >' or]'), or in fact any character, may be quoted by a preceding \'; note when using print -P, however, that this must be doubled as the string is also subject to standard print processing, in addition to any backslashes removed by a double quoted string: the worst case is thereforeprint -P "%<\\<<..."'.

If the string is longer than the specified truncation length, it will appear in full, completely replacing the truncated string. The part of the prompt string to be truncated runs to the end of the string, or to the end of the next enclosing group of the %(' construct, or to the next truncation encountered at the same grouping level (i.e. truncations inside a%(' are separate), which ever comes first. In particular, a truncation with argument zero (e.g. %<<') marks the end of the range of the string to be truncated while turning off truncation from there on. For example, the prompt '%10<...<%~%<<%# ' will print a truncated representation of the current directory, followed by a%' or #', followed by a space. Without the%<<', those two characters would be included in the string to be truncated.

官方文档地址：http://zsh.sourceforge.net/Doc/Release/zsh_12.html


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
  packetcontrol 连接不上服务器
  You would need to add the following: "channels": [ "https://packagecontrol.io/channel_v3.json", "https://web.archive.org/web/20150905194312/https://packagecontrol.io/channel_v3.json" ]

  to the JSON that is found in the menu under: Preferences > Package Settings > Package Control > Settings - User

  As written by MattDMo, apparently the hosting company for Package Control was under a DDoS attack and therefore there was the downtime, everything seems in order right now so I will suggest to remove the channels from the Settings - User JSON underneath Preferences > Package Settings > Package Control > Settings - User
  instal 里面搜 Material
  To activate this awesome theme, add in your current settings this code:
  
  {
      "theme": "Material-Theme.sublime-theme",
      "color_scheme": "Packages/Material Theme/schemes/Material-Theme.tmTheme",
  }

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => SYNTAX 注解
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
SYNTAX

*syntax.txt*    For Vim version 7.0.  最近更新: 2006年5月


                  VIM 参考手册    by Bram Moolenaar
                                译者: Willis
                                http://vimcdoc.sf.net


语法高亮                        *syntax* *syntax-highlighting* *coloring*

语法高亮使得 Vim 可以用不同的字体或颜色显示文本的不同部分。这些部分可以是特定
的关键字，或者匹配某模式的文本。Vim 不会分析整个文件 (为了保持快速)，所以高亮
功能有其限制。词法高亮或者是一个更合适的名字，但既然大家都使用语法高亮，我们也
就如此称呼。

Vim 支持所有终端上的语法高亮。但因为多数普通的终端只有有限的高亮的选择，GUI 版
本 gvim 的语法高亮的效果最好。

用户手册里:
|usr_06.txt| 介绍语法高亮。
|usr_44.txt| 介绍如何写语法文件。

1.  快速入门                    |:syn-qstart|
2.  语法文件                    |:syn-files|
3.  语法载入过程                |syntax-loading|
4.  语法文件附注                |:syn-file-remarks|
5.  定义语法                    |:syn-define|
6.  :syntax 参数                |:syn-arguments|
7.  语法模式                    |:syn-pattern|
8.  语法簇                      |:syn-cluster|
9.  包含语法文件                |:syn-include|
10. 同步                        |:syn-sync|
11. 列出语法项目                |:syntax|
12. Highlight 命令              |:highlight|
13. 链接组                      |:highlight-link|
14. 清理                        |:syn-clear|
15. 高亮标签                    |tag-highlight|
16. 彩色 xterm                  |xterm-color|

{Vi 无此功能}

如果编译时关闭了 |+syntax| 特性，就不会有语法高亮的功能。

1. 快速入门                                             *:syn-qstart*

                                                *:syn-enable* *:syntax-enable*
这个命令打开语法高亮:

        :syntax enable

实际上，它只是执行如下命令
        :source $VIMRUNTIME/syntax/syntax.vim

如果没有设置 VIM 环境变量，Vim 会试图用其它方法找到该路径 (见|$VIMRUNTIME|)。
通常总能找到，如果不行，你可以自己设置 VIM 环境变量为存放 Vim 相关文件所在的
目录。例如，如果你的语法文件放在 "/usr/vim/vim50/syntax" 目录，设置
$VIMRUNTIME 为 "/usr/vim/vim50"。启动 Vim 前，你必须在外壳上进行此设置。

                                                        *:syn-on* *:syntax-on*
":syntax enable" 命令会保持你当前的色彩设置。这样，不管在使用此命令的前后，你
都可以用 ":highlight" 命令设置你喜欢的颜色。如果你希望 Vim 用缺省值覆盖你自己
的，只要用:
        :syntax on

                                        *:hi-normal* *:highlight-normal*
如果你运行在 GUI 环境里，你可以这样得到黑底白字:
        :highlight Normal guibg=Black guifg=White
关于色彩终端，见 |:hi-normal-cterm|。
关于设置你自己的语法高亮色彩，见 |syncolor|。

注意: MS-DOS 和 Windows 上的语法文件以 <CR><NL> 结束每一行。Unix 上则以 <NL>
结尾。这意味着你需要为自己的系统选择合适的文件。不过，在 MS-DOS 和 Windows
上，如果 'fileformats' 选项非空，会自动选择正确的格式。

注意: 使用反转视频时 ("gvim -fg white -bg black")，'background' 的缺省值直到
GUI 窗口打开时才会设置。这发生在 |gvimrc| 的读入之后，从而会使用错误的缺省高
亮。要在打开高亮前设置 'background' 的缺省值，在 |gvimrc| 文件里包含 ":gui" 命
令:

   :gui         " 打开窗口并设置 'background' 的缺省值
   :syntax on   " 启动语法高亮，使用 'background' 来设置颜色

注意: 在 |gvimrc| 里使用 ":gui" 意味着 "gvim -f" 不会在前台打开！这时，要使用
":gui -f"。


你可以用这个命令切换语法的打开/关闭
   :if exists("syntax_on") | syntax off | else | syntax enable | endif

要把它放到映射里，你可以用:
   :map <F7> :if exists("syntax_on") <Bar>
        \   syntax off <Bar>
        \ else <Bar>
        \   syntax enable <Bar>
        \ endif <CR>
[使用 |<>| 记法，按本义输入]

细节
":syntax" 命令是用执行文件脚本实现的。要了解它到底干了什么，察看以下文件:
    命令                文件 
    :syntax enable      $VIMRUNTIME/syntax/syntax.vim
    :syntax on          $VIMRUNTIME/syntax/syntax.vim
    :syntax manual      $VIMRUNTIME/syntax/manual.vim
    :syntax off         $VIMRUNTIME/syntax/nosyntax.vim
另见 |syntax-loading|。

2. 语法文件                                                     *:syn-files*

某个语言的语法和高亮命令通常存在一个语法文件里。命名惯例是: "{name}.vim"。其
中，{name} 是语言的名字或者缩写 (一旦在 DOS 文件系统上，要适用 8.3 字符的名字
限制)。
例如:
        c.vim           perl.vim        java.vim        html.vim
        cpp.vim         sh.vim          csh.vim

语法文件可以包含任何 Ex 命令，就像 vimrc 文件那样。但应该只有适用于特定语言的
命令才放在里面。如果该语言是另外一个语言的超集，它可以包含那个语言对应的文件。
例如，cpp.vim 可以包含 c.vim 文件:
   :so $VIMRUNTIME/syntax/c.vim

.vim 文件通常使用自动命令载入。例如:
   :au Syntax c     runtime! syntax/c.vim
   :au Syntax cpp   runtime! syntax/cpp.vim
这些命令通常出现在 $VIMRUNTIME/syntax/synload.vim 文件里。

如果你有多个文件，可以用文件类型作为目录名。该目录下的所有 "*.vim" 文件都会被
使用。例如:
        ~/.vim/after/syntax/c/one.vim
        ~/.vim/after/syntax/c/two.vim


创 立 你 自 己 的 语 法 文 件                           *mysyntaxfile*

一旦你创立自己的语法文件，并且需要 Vim 在使用 ":syntax enable" 的时候自动调用
它们的时候，按如下操作进行:

1. 建立自己的用户运行时目录。通常，把它放在 'runtimepath' 选项的第一项。Unix
的例子:
        mkdir ~/.vim

2. 在其中建立 "syntax" 目录。Unix 上:
        mkdir ~/.vim/syntax

3. 编写 Vim 语法文件。或者从 internet 下载。然后写入你的 syntax 目录。例如，对
于 "mine" 语言的语法:
        :w ~/.vim/syntax/mine.vim

现在你可以手动启动语法文件:
        :set syntax=mine
这时，你并不需要退出 Vim。

如果你想 Vim 也实现文件类型的检测，见 |new-filetype|。

如果你想为多个用户设立系统，而不希望每个用户增加相同的语法文件的话，可以使用
'runtimepath' 里的其它目录。


添 加 到 已 存 在 的 语 法 文 件                *mysyntaxfile-add*

如果你对已有的语法文件大体满意，只需要增加或者修正一些高亮项目，执行以下步骤即
可:

1. 建立你的 'runtimepath' 里的用户目录，见上。

2. 在那里建立目录 "after/syntax"。Unix 上:
        mkdir ~/.vim/after
        mkdir ~/.vim/after/syntax

3. 编写 Vim 脚本，包含你希望使用的命令。例如，要在 C 语法里改变颜色:
        highlight cComment ctermfg=Green guifg=Green

4. 把该文件写道 "after/syntax" 目录。使用该语法的名字，另加上 ".vim"。对于我们
的 C 语法:
        :w ~/.vim/after/syntax/c.vim

这样就行了。下一次你编辑 C 文件时，Comment 色彩就不会一样了。你甚至不需要重启
Vim。


替 换 已 存 在 的 语 法 文 件                   *mysyntaxfile-replace*

如果你不喜欢发布的语法文件版本，或者你下载了新版本。可以采用上述的
|mysyntaxfile| 相同的步骤。只要确保你写的语法文件在 'runtimepath' 较早的位置就
可以了。Vim 只会载入第一个找到的语法文件。


命 名 惯 例
                                    *group-name* *{group-name}">{group-name}* *E669* *W18*
高亮或者语法组的名字必须由 ASCII 字母，数字和下划线组成。如使用正规表达式表示:
"[a-zA-Z0-9_]*"。

要允许每个用户选择他自己喜欢的色彩系列，许多语言应该使用相同的高亮组名。以下是
建议的组名 (如果语法高亮能够正确工作，你应该能看到实际的颜色，除了 "Ignore" 以
外):

        *Comment        v 任何注释

        *Constant       v 任何常数
         String         v 一个字符串常数: "这是一个字符串"
         Character      v 一个字符常数: 'c'、'\n'
         Number         v 一个数字常数: 234、0xff
         Boolean        v 一个布尔型常数: TRUE、false
         Float          v 一个浮点常数: 2.3e10

        *Identifier     v 任何变量名
         Function       v 函数名 (也包括: 类的方法名)

        *Statement      v 任何语句
         Conditional    v if、then、else、endif、switch 等
         Repeat         v for、do、while、etc.
         Label          v case、default 等
         Operator       v "sizeof"、"+"、"*" 等
         Keyword        v 任何其它关键字
         Exception      v try、catch、throw

        *PreProc        v 通用预处理命令
         Include        v 预处理命令 #include
         Define         v 预处理命令 #define
         Macro          v 等同于 Define
         PreCondit      v 预处理命令 #if、#else、#endif 等

        *Type           v int、long、char 等
         StorageClass   v static、register、volatile 等
         Structure      v struct、union、enum 等
         Typedef        v 一个 typedef

        *Special        v 任何特殊符号
         SpecialChar    v 常数中的特殊字符
         Tag            v 这里可以使用 CTRL-]
         Delimiter      v 需要注意的字符
         SpecialComment v 注释里的特殊字符
         Debug          v 调试语句

        *Underlined     v 需要突出的文本，HTML 链接

        *Ignore         v 留空，被隐藏

        *Error          v 任何有错的构造

        *Todo           v 任何需要特殊注意的部分；多是关键字 TODO FIXME 和 XXX

* 标记的名字是主要组，其它是次要组。对主要组而言，"syntax.vim" 文件包含缺省的
高亮设置。次要组则链接到主要组。所以它们拥有相同的高亮设置。不过，你可以通过
":highlight" 命令在 "syntax.vim" 文件之后改变所有组的缺省值。

注意高亮组的名字对大小写不敏感。"String" 和 "string" 可用来表示相同的组。

以下名字是保留字，它们不应用作组名:
        NONE   ALL   ALLBUT   contains   contained

3. 语法载入过程                                         *syntax-loading*

这里解释命令 ":syntax enable" 执行的细节。Vim 初始化自身时，它寻找运行时文件的
位置。其值用来设置这里使用的变量 |$VIMRUNTIME|。

":syntax enable" 和 ":syntax on" 完成以下步骤:

    执行 $VIMRUNTIME/syntax/syntax.vim
    |
    +-  清除旧的语法: 执行 $VIMRUNTIME/syntax/nosyntax.vim
    |
    +-  先执行 'runtimepath' 里的 syntax/synload.vim
    |   |
    |   +-  为语法高亮设置色彩。如果已经定义了色彩方案，使用 ":colors {name}"
    |   |   再次载入。不然，执行 ":runtime! syntax/syncolor.vim"。":syntax on"
    |   |   会覆盖已有的颜色，而 ":syntax enable" 只会设置没有设置过的组。
    |   |
    |   +-  设置 syntax 自动命令，以便在设置 'syntax' 选项时，自动载入合适的语
    |   |   法文件。 *synload-1*
    |   |
    |   +-  通过 |mysyntaxfile| 变量，载入用户可选的文件。这只是为了和 Vim 5.x
    |   |   兼容。 *synload-2*
    |
    +-  执行 ":filetype on"，后者又执行 ":runtime! filetype.vim"。它载入任何找
    |   到的 filetype.vim。其中，总会执行 $VIMRUNTIME/filetype.vim。后者执行:
    |   |
    |   +-  根据后缀名，安装自动命令来设置 'filetype' 选项。这为已知的文件类型
    |   |   建立了文件名和文件类型的联系。 *synload-3*
    |   |
    |   +-  通过 *myfiletypefile* 变量，载入用户可选的文件。这只是为了和 Vim
    |   |   5.x 兼容。 *synload-4*
    |   |
    |   +-  安装自动命令，在没有检测到文件类型时执行 scripts.vim 。
    |   |   *synload-5*
    |   |
    |   +-  执行 $VIMRUNTIME/menu.vim，设置 Syntax 菜单。|menu.vim|
    |
    +-  安装 FileType 自动命令，在检测到文件类型时，设置 'syntax' 选项。
    |   *synload-6*
    |
    +-  执行 syntax 自动命令，为每个已经载入的缓冲区启动语法高亮。


载入文件时，Vim 这样查找相关的语法文件:

    文件的载入激活 BufReadPost 自动命令。
    |
    +-  如果和 |synload-3| 中的一个自动命令匹配 (已知的文件类型) 或者
    |   |synload-4| (用户的文件类型)，'filetype' 选项设为文件的所属类型。
    |
    +-  如果文件类型没有找到，激活 |synload-5| 中的自动命令，并在
    |   'runtimepath' 里找寻 scripts.vim。其中，总是会执行
    |   $VIMRUNTIME/scripts.vim。后者执行以下步骤。
    |   |
    |   +-  通过 *myscriptsfile* 变量，载入用户可选的文件。这只是为了和 Vim
    |   |   5.x 兼容。
    |   |
    |   +-  如果文件类型仍然未知，检查文件的内容，并使用类似于
    |       "getline(1) =~ pattern" 的检查确定文件类型能否识别，并设置
    |       'filetype'。
    |
    +-  如果文件类型被确定并且设置了 'filetype'，激活 FileType 自动命令，见上
    |   面的 |synload-6|。根据确定的文件类型设置 'syntax'。
    |
    +-  上面设置 'syntax' 选项的步骤激活 |synload-1| (和 |synload-2|) 设置的自
    |   动命令。它会使用以下命令找到 'runtimepath' 里的主语法文件:
    |           runtime! syntax/<name>.vim
    |
    +-  激活任何用户安装的 FileType 或 Syntax 自动命令。这可以用来为某项语法修
        正高亮方式。

4. 语法文件附注                                         *:syn-file-remarks*

                                                *b:current_syntax-variable*
根据当前激活的是哪部语法，Vim 把载入的语法的名字保存在 "b:current_syntax" 变量
里。例如:
   :au BufReadPost * if b:current_syntax == "csh"
   :au BufReadPost *   做一些事
   :au BufReadPost * endif


2HTML                                           *2html.vim* *convert-to-HTML*

它本身并不是语法文件，只是一个把当前窗口转换成 HTML 的脚本。Vim 打开一个新窗
口，在那里它构造 HTML 文件。

你不应该设置 'filetype' 或 'syntax' 选项为 "2html"！执行此脚本，以转换当前文
件:

        :runtime! syntax/2html.vim

警告: 这挺慢的！
                                                        *:TOhtml*
也可以使用 ":TOhtml" 用户命令。它是在一个标准插件里定义的。":TOhtml" 可用于行
范围和可视区域:

        :10,40TOhtml

保存结果文件以后，你可以使用任何 HTML 察看器浏览，比如 Netscape。那里的颜色应
该和你在 Vim 里看到的一模一样。

要限制转换的行范围，设置 "html_start_line" 和 "html_end_line" 分别为要转换的第
一行和最后一行。例如，要指定最近设置的可视区域:

        :let html_start_line = line("'<")
        :let html_end_line = line("'>")

行的标号方式根据 'number' 选项和 Number 高亮属性而定。通过设置
"html_number_lines" 为一非零值，你可以让输出的 HTML 强制给行编号:
   :let html_number_lines = 1
设为零则强制关闭行号:
   :let html_number_lines = 0
要回到缺省情况，即使用 'number' 的设置，可删除此变量:
   :unlet html_number_lines

HTML 里关闭折叠的处理和实际显示的效果一样。如果不想如此，启动 2html 前用 |zR|
命令，或者:
   :let html_ignore_folding = 1

缺省情况生成为旧版本的浏览器优化的 HTML。如果你希望使用层叠样式表 (CSS1) 来设
置属性 (产生相当简洁且合法的 HTML 4 文件)，可用:
   :let html_use_css = 1

缺省使用 "<pre>" 和 "</pre>" 围绕文本。使得这些文本看起来和 Vim 的一致，但没有
回绕。如果你希望有回绕，且可以忍受不太一致的外观，可使用:
   :let html_no_pre = 1
这会在每行结束的地方使用 <br>，而用 "&nbsp;" 来显示连续的空格。

'encoding' 的当前值用于指定 HTML 文件的字符集。这只适用于 'encoding' 的值有对
应的 HTML 字符集名字的时候。要改变这种机制，设置 g:html_use_encoding 为要用的
字符集名:
   :let html_use_encoding = "foobar"
如果不想产生指定字符集的那行，设置 g:html_use_encoding 为空字符串:
   :let html_use_encoding = ""
要回到自动的机制，删除 g:html_use_encoding 变量:
   :unlet html_use_encoding

关于 diff 模式，多于三行的填充行序列显示为三行，中间行提到插入的总行数。如果你
宁愿看到所有的插入行，用:
    :let html_whole_filler = 1
要回到三行的显示方式:
    :unlet html_whole_filler

                                            *convert-to-XML* *convert-to-XHTML*
另一个选择是使用该脚本产生 XHTML (XML 兼容的 HTML)。这可以通过设置 "use_xhtml"
变量完成:
    :let use_xhtml = 1
要关闭此选择，删除该变量:
    :unlet use_xhtml
这里产生的 XHTML 文件可以在 DocBook XML 文档里使用。见:
        http://people.mech.kuleuven.ac.be/~pissaris/howto/src2db.html

评注:
- 只有在 GUI 支持的版本里，才能工作。如果没有运行 GUI (可能仍然使用 X11)，或许
  也可以，但是效果不一定好 (颜色可能不对)。
- 较旧的浏览器不会显示背景色。
- 你可以在大多数浏览器里打印文件 (而且有颜色)！

此处是一个如何在 Unix 外壳上给所有的 .c 和 .h 文件运行此脚本的例子:
   for f in *.[ch]; do gvim -f +"syn on" +"run! syntax/2html.vim" +"wq" +"q" $f; done


ABEL                                            *abel.vim* *ft-abel-syntax*

ABEL 高亮设置提供一些用户定义的选项。要打开这些选项，给相应的选项设置任意值。
例如:
        :let abel_obsolete_ok=1
可用 ":unlet" 关闭。例如:
        :unlet abel_obsolete_ok

变量                            高亮 
abel_obsolete_ok                废弃的关键字接受为 statement，而非 error
abel_cpp_comments_illegal       不把 '//' 解释为行内注释的引导符


ADA                                             *ada.vim* *ft-ada-syntax*

本模块为 1995 年版的 Ada ("Ada95") 设计，它支持面向对象编程，受保护的类型，等
等。它也能处理为原始 Ada 语言的代码 ("Ada83" 或 "Ada87")，不过 Ada83 代码里如
果使用 Ada95 才有的关键字的话，颜色显示会不正确 (不过这样的代码本来也应该修
正)。更多关于 Ada 的信息，见 http://www.adapower.com。

Ada 模式正确地处理一些情况。例如，它知道 "-5" 里的 "-" 是数字的一部分，但
"A-5" 里的该字符则是操作符。通常，引用别的编译单元的 "with" 或 "use" 语句使用
C 里面的 "#include" 相同的色彩。如果你为 "Conditional" 或 "Repeat" 组指定了不
同的色彩，那么 "end if" 和 "end loop" 会根据它们所在的组被分别标色。你可以用
vim 的 "highlight" 命令来给出不同的颜色 (例如，要改变循环的显示方式，输入命令
":hi Repeat"，后面跟色彩的规格说明；在普通终端上，色彩规格 ctermfg=White 通常
就有不错的显示效果)。

本 Ada 模式可以设置若干选项。给选项赋值就可以打开。例如，要打开一个选项:
   let ada_standard_types = 1
可用 ":unlet" 关闭。例如:
   unlet ada_standard_types = 1
使用 ":" 并在命令行输入这些命令就可以在载入 Ada 文件时临时设置选项。要永久设
置，把 "let" 命令加到你的 "~/.vimrc" 文件里，无需冒号。

以下是 Ada 模式选项:

变量                     动作   
ada_standard_types       高亮 Standard 包里的类型 (例如，"Float")
ada_space_errors         高亮空格里的错误...
ada_no_trail_space_error   但忽略行尾的空格
ada_no_tab_space_error     但忽略空格之后的制表
ada_withuse_ordinary     把 "with" 和 "use" 显示为普通的关键字
                           (用于引用别的编译单元时，它们不再特殊高亮)。
ada_begin_preproc        使用 C 预处理命令的色彩来显示所有 begin 风格的关键
                         字。

即使在慢速 (90Mhz) PC 上，该模式也很快。但如果你还是觉得速度无法忍受，可以打开
ada_withuse_ordinary。


ANT                                             *ant.vim* *ft-ant-syntax*

ant 语法文件缺省提供了 javascript 和 python 的语法高亮。其他脚本语言的语法高亮
可以通过 AntSyntaxScript() 函数安装。它接受的第一个参数是标签名，而第二个是脚
本语法文件名。例如:

        :call AntSyntaxScript('perl', 'perl.vim')

会为下面的 ant 代码提供 Perl 的语法高亮

        <script language = 'perl'><![CDATA[
            # 这里的一切都作为 perl 脚本高亮
        ]]></script>

|mysyntaxfile-add| 说明如何永久的安装脚本语言。


APACHE                                          *apache.vim* *ft-apache-syntax*

Apache 语法文件提供的语法高亮取决于 Apache HTTP 服务器的版本，缺省为 1.3.x。设
置 "apache_version" 为 Apache 的相应版本 (字符串形式) 可以得到其它版本的高亮方
式。例如:

        :let apache_version = "2.0"


                *asm.vim* *asmh8300.vim* *nasm.vim* *masm.vim* *asm68k*
ASSEMBLY        *ft-asm-syntax* *ft-asmh8300-syntax* *ft-nasm-syntax*
                *ft-masm-syntax* *ft-asm68k-syntax* *fasm.vim*

匹配 "*.i" 的可以是 Progress 或者汇编文件。如果自动检测对你不工作，或者你从来
不编辑 Progress，在你启动的 vimrc 里这么用:
   :let filetype_i = "asm"
把 "asm" 替换成你实际使用的汇编语言。

许多类型的汇编语言都使用相同的文件扩展名。因而，你或者需要自己选择类型，或者在
汇编文件里增加使 Vim 能识别的行。目前，包含了以下的语法文件:
        asm             GNU 汇编 (缺省)
        asm68k          Motorola 680x0 汇编
        asmh8300        Hitachi H-8300 版本的 GNU 汇编
        ia64            Intel Itanium 64
        fasm            Flat 汇编 (http://flatassembler.net)
        masm            Microsoft 汇编 (可能适用于任何 80x86)
        nasm            Netwide 汇编
        tasm            Turbo 汇编 (提供到 Penitum 和 MMX 的 80x86 操作码)
        pic             PIC 汇编 (目前支持 PIC16F84)

最灵活的方式是在你的汇编文件里加上如下一行:
        :asmsyntax=nasm
把 "nasm" 换成实际的汇编语法的名字。该行必须是文件头五行中的一行。

语法类型可以为某个缓冲区定制。方法是设置 b:asmsyntax 变量:
        :let b:asmsyntax=nasm

如果没有设置 b:asmsyntax，不管是自动还是手动，就会使用全局变量 asmsyntax 的
值。它可以看作是缺省的汇编语言:
        :let asmsyntax=nasm

如果什么都没有定义，最后就假定是 "asm" 语法。


Netwide 汇编器 (nasm.vim) 可选高亮特性 

要打开特性:
        :let   {variable}=1|set syntax=nasm
要关闭特性:
        :unlet {variable}  |set syntax=nasm

变量                    高亮 
nasm_loose_syntax       非正式的分析器允许的语法不视为错误 (取决于分析器；不推
                        荐)
nasm_ctx_outside_macro  宏之外的上下文不视为错误
nasm_no_warn            潜在有危险的语法不视为 Todo 那样的警告


ASPPERL 和 ASPVBS                       *ft-aspperl-syntax* *ft-aspvbs-syntax*

*.asp 和 *.asa 文件可以是 Perl 或者 Visual Basic 脚本。因为很难检测，你可以设
置两个全局变量，来告诉 Vim 你要用哪一个。Perl 脚本可用:
        :let g:filetype_asa = "aspperl"
        :let g:filetype_asp = "aspperl"
Visual Basic 可用:
        :let g:filetype_asa = "aspvbs"
        :let g:filetype_asp = "aspvbs"


BAAN                                                *baan.vim* *baan-syntax*

baan.vim 提供 BaanIV 到 SSA ERP LN 发行版的 BaanC 的语法支持，用于 3 GL 和 4
GL 编程。支持很多的标准宏定义/常数。

如果你在某个 |.vimrc| 里指定下面这行，不合编码标准的一些特殊错误会被报告:
        let baan_code_stds=1

*baan-folding*

使用下面提到的变量，可以在不同层次上打开语法折叠 (在 |.vimrc| 里设置)。源代码
块和 SQL 上越复杂的折叠越需要 CPU。

要允许折叠并在函数级别上打开折叠:
        let baan_fold=1
可以在源代码块级别上打开折叠，如 if、while、for，... 这里开始/结束关键字之前的
缩进必须一致 (空格不等于制表)。
        let baan_fold_block=1
可以为内嵌的 SQL 块打开折叠，如 SELECT、SELECTDO、SELECTEMPTY，... 这里开始/结
束关键字之前的缩进必须一致 (空格不等于制表)。
        let baan_fold_sql=1

注意: 代码块级别的折叠可能产生许多小的折叠。建议在 .vimrc 里用 |:set| 设置选项
'foldminlines' 和 'foldnestmax'，在 .../after/syntax/baan.vim 里用 |:setlocal|
设置也可以 (见 |after-directory|)。例如:
        set foldminlines=5
        set foldnestmax=6


BASIC                   *basic.vim* *vb.vim* *ft-basic-syntax* *ft-vb-syntax*

Visual Basic 和 "普通的" Basic 都使用扩展名 ".bas"。要检测使用的是哪一个，Vim
在文件的头五行检查字符串 "VB_Name"。如果没找到，文件类型将是 "basic"，不然就是
"vb"。带 ".frm" 扩展名的文件总被视为 Visual Basic 类型。


C                                                       *c.vim* *ft-c-syntax*

C 高亮的一些设置是可选的。要打开，给相应的变量赋任何值。例如:
        :let c_comment_strings=1
可用 ":unlet" 关闭。例如:
        :unlet c_comment_strings

变量                    高亮 
c_gnu                   GNU gcc 专用的项目
c_comment_strings       注释里的字符串和数字
c_space_errors          行尾的空格和 <Tab> 之前的空格
c_no_trail_space_error   ... 不包括行尾的空格
c_no_tab_space_error     ... 不包括 <Tab> 之前的空格
c_no_bracket_error      不高亮 {}；如果在 [] 里面视为错误
c_no_curly_error        不高亮 {}；如果在 [] 和 () 里面视为错误；
                                除了出现在首列的 { 和 } 以外
c_no_ansi               不使用 ANSI 标准类型和常数
c_ansi_typedefs          ... 但使用 ANSI 标准类型
c_ansi_constants         ... 但使用 ANSI 标准常数
c_no_utf                不高亮字符串里的 \u 和 \U
c_syntax_for_h          *.h 文件使用 C 语法，而不是 C++ 的
c_no_if0                不把 "#if 0" 块高亮为注释
c_no_cformat            不高亮字符串里的 %-格式
c_no_c99                不高亮 C99 标准的项目

如果 'foldmethod' 设为 "syntax"，那么 /* */ 注释和 { } 块成为折叠。如果你不想
让注释成为折叠:
        :let c_no_comment_fold = 1
"#if 0" 块也被折叠，除非:
        :let c_no_if0_fold = 1

如果你注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正的话，尝试设置
"c_minlines" 内部变量为较大的值:
        :let c_minlines = 100
这使得语法同步在第一个显示行之前的 100 行开始。缺省值为 50 (如果设置了
c_no_if0，则为 15)。使用较大的值的缺点是重画会变慢。

如果使用 "#if 0" / "#endif" 风格的注释高亮，注意它只适用于 "#if 0" 出现在窗口
顶部往上不超过 "c_minlines" 行的场合。如果你有很长的 "#if 0" 构造，它不会被正
确地高亮。

要匹配注释里的附加项目，使用 cCommentGroup 簇。例如:
   :au Syntax c call MyCadd()
   :function MyCadd()
   :  syn keyword cMyItem contained Ni
   :  syn cluster cCommentGroup add=cMyItem
   :  hi link cMyItem Title
   :endfun

ANSI 常数使用 "cConstant" 组高亮。这包括 "NULL"、"SIG_IGN" 还有其它。但不包
括，比如说，"TRUE"。因为它不在 ANSI 标准里。如果你觉得弄不清楚，删除 cConstant
高亮:
        :hi link cConstant NONE

如果你看到 '{' 和 '}' 被高亮为错误，而实际并非如此的时候，复位 cErrInParen 和
cErrInBracket 的高亮。

如果想在你的 C 文件里使用折叠，可以在 'runtimpath' 的 "after" 目录下的一个文件
里加上这些行。Unix 上，这会是 ~/.vim/after/syntax/c.vim.
    syn region myFold start="{" end="}" transparent fold
    syn sync fromstart
    set foldmethod=syntax

CH                                              *ch.vim* *ft-ch-syntax*

C/C++ 解释器。Ch 的语法高亮和 C 相似，它基于 C 语法文件。|c.vim| 说明所有 C 可
用的设置。

设置此变量，告诉 Vim 用 Ch 语法来处理 *.h 文件，而不是 C 或 C++ 语法:
        :let ch_syntax_for_h = 1


CHILL                                           *chill.vim* *ft-chill-syntax*

Chill 语法高亮和 C 类似。可用的设置见 |c.vim|。此外，还有:

chill_space_errors      类似于 c_space_errors
chill_comment_string    类似于 c_comment_strings
chill_minlines          类似于 c_minlines


CHANGELOG                               *changelog.vim* *ft-changelog-syntax*

ChangeLog 支持行首的空格高亮。如果你不喜欢，在你的 .vimrc 里加入下行:
        let g:changelog_spacing_errors = 0
下次你编辑 changelog 文件时，就会应用。你也可以使用
"b:changelog_spacing_errors" 来为每个缓冲区分别设置 (在载入语法文件以前)。

你可以改变现在使用的高亮，例如把空格标记为错误:
        :hi link ChangelogError Error
或者避免高亮:
        :hi link ChangelogError NONE
这些会立即生效。


COBOL                                           *cobol.vim* *ft-cobol-syntax*

COBOL 高亮对传统的代码和新开发的代码有不同的需要。这来自于需求的差异 (维护还是
开发)，以及一些其它因素。要使用传统代码的高亮，在 .vimrc 里加上此行:
        :let cobol_legacy_code = 1
要再次关闭，可用:
        :unlet cobol_legacy_code


COLD FUSION                     *coldfusion.vim* *ft-coldfusion-syntax*

ColdFusion 有 HTML 注释的自己的版本。要打开 ColdFusion 风格的注释高亮，在你的
启动文件里加上此行:

        :let html_wrong_comments = 1

ColdFusion 语法文件是基于 HTML 的语法文件的。


CSH                                             *csh.vim* *ft-csh-syntax*

这里讨论名为 "csh" 的外壳。注意 有的系统实际使用的 tcsh.

要检测一个文件是 csh 还是 tcsh 异常困难。有的系统把 /bin/csh 符号链接到
/bin/tcsh，使得区别 csh 和 tcsh 几乎不可能。如果 VIM 猜错，你可以自己设置
"filetype_csh" 变量。要使用 csh:

        :let filetype_csh = "csh"

要使用 tcsh:

        :let filetype_csh = "tcsh"

带 tcsh 扩展名的脚本或者 tcsh 的标准文件名 (.tcshrc、tcsh.tcshrc、tcsh.login)
会使用文件类型 tcsh。其它的 tcsh/csh 脚本也会被识别为 tcsh，_除非_存在
"filetype_csh" 变量。如果存在 "filetype_csh" 变量，文件类型会设为该变量的值。


CYNLIB                                          *cynlib.vim* *ft-cynlib-syntax*

Cynlib 文件是使用 Cynlib 类库的 C++ 文件。它们使用 C++ 来为硬件建模和模拟。通
常 Cynlib 文件使用 .cc 或 .cpp 扩展名，这使得它们和普通的 C++ 文件难以区别。因
而，要使用 Cynlib 为 .cc 文件高亮，在你的 .vimrc 文件里加上此行:

        :let cynlib_cyntax_for_cc=1

cpp 文件也类似 (该扩展名通常为 Windows 使用)

        :let cynlib_cyntax_for_cpp=1

要再次关闭，可用:

        :unlet cynlib_cyntax_for_cc
        :unlet cynlib_cyntax_for_cpp


CWEB                                            *cweb.vim* *ft-cweb-syntax*

匹配 "*.w" 的文件可为 Progress 文件或者 cweb 文件。如果自动检测不行，或者你从
来不编辑 Progress，可以在启动的 vimrc 文件里用:
   :let filetype_w = "cweb"


DESKTOP                                    *desktop.vim* *ft-desktop-syntax*

该语法文件的主要目的是根据 freedesktop.org 标准:
http://pdx.freedesktop.org/Standards/ 来高亮 .desktop 和 .directory 文件。但实
际上，几乎没人完全实现了标准。所以，它实际被用来高亮所有的 Unix ini 文件。如果
你希望强制使用符合标准的严格的高亮方式，在 vimrc 文件放上:
        :let enforce_freedesktop_standard = 1


DIRCOLORS                              *dircolors.vim* *ft-dircolors-syntax*

dircolors 工具的高亮定义有一个选项。它的存在是为了和 Slackware GNU/Linux 发布
版本里的该命令兼容。它增加了一些多数版本忽略的关键字。在 Slackware 系统中，该
工具接受这些关键字并在处理中应用。要允许使用 Slackware 关键字，在你的启动文件
里加入如下一行:
        let dircolors_is_slackware = 1


DOCBOOK                                 *docbk.vim* *ft-docbk-syntax* *docbook*
DOCBOOK XML                             *docbkxml.vim* *ft-docbkxml-syntax*
DOCBOOK SGML                            *docbksgml.vim* *ft-docbksgml-syntax*

有两种类型的 DocBook 文件: SGML 和 XML。要指定使用那种类型，需要设置
"b:docbk_type" 变量。如果 Vim 能够识别，它会自动设置该变量。如果 Vim 猜不到，
缺省的类型是 XML。
你可以手动设置:
        :let docbk_type = "sgml"
或者:
        :let docbk_type = "xml"
你需要在载入语法文件前作如此设置，这有点复杂。
更简单的方法是设置文件类型为 "docbkxml" 或 "docbksgml":
        :set filetype=docbksgml
或:
        :set filetype=docbkxml


DOSBATCH                                *dosbatch.vim* *ft-dosbatch-syntax*

DOS 批处理文件的高亮有一个选项。它和 Windows 2000 的命令解释器的新扩展有关，可
以通过 dosbatch_cmdextversion 变量控制。Windows NT 上，它应该取值为 1，Windows
2000 应该为 2。下面这行可以选择你想要的版本:

   :let dosbatch_cmdextversion = 1

如果没有定义该变量，缺省设为 2，以支持 Windows 2000 版本。

第二个选项控制 *.btm 文件是否被识别为 "dosbatch" 类型 (MS-DOS 批处理文件) 或
"btm" 类型 (4DOS 批处理文件)。缺省使用后者。下行可以让你选择前者:

   :let g:dosbatch_syntax_for_btm = 1

如果此变量无定义或为零，选择 btm 语法。



DOXYGEN                                         *doxygen.vim* *doxygen-syntax*

Doxygen 使用特殊的文档格式生成代码文档 (和 Javadoc 类似)。本语法脚本为 c、cpp
和 idl 文件加入 Doxygen 的高亮，Java 应该也能用。

有几个办法可以打开 Doxygen 格式。首先，在文件的模式行上可以给 syntax 加入
".doxygen"，进行显式设置。示例:
        :set syntax=c.doxygen
或
        // vim:syntax=c.doxygen

要让任何文件类型使用 Doxygen 格式，在 .vimrc 里为每个文件类型加上下行，其中
{filetype} 用相应的值替代。
        :let g:syntax_extra_{filetype}='doxygen'

对于 c、cpp 和 idl 文件，也可以设置全局或局部于缓冲区变量 load_doxygen_syntax
来自动完成这个操作。在 .vimrc 里加上
        :let g:load_doxygen_syntax=1

有一些变量影响语法高亮，它们大多和非标准的高亮选项有关。

变量                            缺省    效果 
g:doxygen_enhanced_color
g:doxygen_enhanced_colour       0       Doxygen 注释使用非标准的高亮。

doxygen_my_rendering            0       关闭 HTML 粗体、斜体和
                                        html_my_rendering 下划线的高亮。

doxygen_javadoc_autobrief       1       如果为 0，关闭 Javadoc autobrief 色彩
                                        高亮。

doxygen_end_punctuation         '[.]'   匹配 brief 结束标点的正规表达式。

还有一些高亮组值得提提，你可以对它们进行配置。

高亮                            效果 
doxygenErrorComment             如果 code、verbatim 或 dot 段里丢失标点，注释
                                尾部的颜色。
doxygenLinkError                如果丢失 \link 段的 \endlink，注释尾部的颜色。


DTD                                             *dtd.vim* *ft-dtd-syntax*

DTD 语法高亮缺省是大小写敏感的。如果不想如此，在你的启动文件里加入以下一行:

        :let dtd_ignore_case=1

DTD 语法会把未知的标签高亮为错误。如果这很讨厌，在执行 dtd.vim 语法文件之前，
可以用以下设置来关闭:

        :let dtd_no_tag_errors=1

参数实体 (parameter entity) 的名字使用 'Type' 高亮组高亮，标点和 '%' 使用
'Comment'。参数实体的实例使用 'Constant' 高亮组高亮，定界符 % 和 ; 则使用
'Type' 高亮组。以下设置可以关闭这些设定:

        :let dtd_no_param_entities=1

xml.vim 也包含了 DTD 语法文件，用以高亮内嵌的 dtd。

EIFFEL                                  *eiffel.vim* *ft-eiffel-syntax*

尽管 Eiffel 不是大小写敏感的，它的风格指南鼓励如此，而且语法高亮文件也鼓励这样
使用。这使得同一类名的高亮可以不同。如果你想关闭大小写敏感的语法高亮，在启动文
件里加上这行:

        :let eiffel_ignore_case=1

大小写对类名和注释里的 TODO 标记仍然有影响。

相反，要更严格的检查，加入以下诸行之一:

        :let eiffel_strict=1
        :let eiffel_pedantic=1

设置 eiffel_strict 只会捕获以下五个预定义的单词错误的大小写: "Current"、
"Void"、"Result"、"Precursor" 和 "NONE"。用于警告它们可能被不小心用作特性或类
名。

设置 eiffel_pedantic 会非常严格地遵循 Eiffel 风格指南 (例如，大小写字母的任意
混合和其它过时的大写关键字的方法都会被捕获)。

如果希望使用小写版本的 "Current"、"Void"、"Result" 和 "Precursor"，可以用

        :let eiffel_lower_case_predef=1

而不用完全关闭大小写敏感的高亮方式。

一些编译器里已经能够实验性地处理 ISE 推荐的新的创建语法，要打开此语法:

        :let eiffel_ise=1

最后，有的供应商支持十六进制的常数。在你的启动文件里加上这行就可以处理它们

        :let eiffel_hex_constants=1


ERLANG                                          *erlang.vim* *ft-erlang-syntax*

erlang 高亮支持 Erlang 语言 (ERicsson LANGuage)。
Erlang 是大小写敏感的，缺省的扩展名是 ".erl"。

如果你想关闭关键字高亮，在 .vimrc 里加上:
        :let erlang_keywords = 1
如果你想关闭内建函数的高亮，在 .vimrc 里加上:
        :let erlang_functions = 1
如果你想关闭特殊字符的高亮，在 .vimrc 里加上:
        :let erlang_characters = 1


FLEXWIKI                                *flexwiki.vim* *ft-flexwiki-syntax*

FlexWiki 是基于 ASP.NET 的 wiki 包，从 http://www.flexwiki.com 可以获得。

多数常用的 FlexWiki 语法元素都提供了语法高亮。本文件类型插件脚本设置了若干局部
于缓冲区的选项，使 FlexWiki 页面的编辑更加便捷。因为 FlexWiki 把换行符看成新段
落的开始，所以本插件设置 'tw'=0 (无限行长)，置位 'wrap' (回绕长行而不使用水平
滚动)，也置位 'linebreak' (在 'breakat' 包含的字符而不是在屏幕最后一个字符上回
绕)，等等。本插件也包含了一些键盘映射，但它们缺省是关闭的。

如果你打开键盘映射，"j" 和 "k" 和光标键就会在显示行间上下移动。为此，在 .vimrc
里加入:
        :let flexwiki_maps = 1


FORM                                            *form.vim* *ft-form-syntax*

FORM 文件里的语法元素的色彩方案使用缺省模式: Conditional、Number、Statement、
Comment、PreProc、Type 和 String。它遵循 1991 年版荷兰 CAN 组织 J.A.M.
Vermaseren 编著的语言说明书 'Symbolic Manipulation with FORM''。

如果你想自己增加对缺省颜色的修改，需要重新定义以下语法组:

    - formConditional
    - formNumber
    - formStatement
    - formHeaderStatement
    - formComment
    - formPreProc
    - formDirective
    - formType
    - formString

注意 缺省，form.vim 语法文件使用相同的语法组里实现 FORM 预处理器命令和指令。

预定义的 FORM 增强色彩模式可以用来区别头部语句和 FORM 程序本体的语句。要激活此
模式，在你的 vimrc 文件里定义以下变量

        :let form_enhanced_color=1

在深色 gvim 显示中，增强模式也利用了附加的色彩特性。这里，语句
(formStatement) 使用 LightYellow 而不是 Yellow。而条件句 (formConditional) 使
用 LightBlue，以达到更好的区分度。


FORTRAN                                 *fortran.vim* *ft-fortran-syntax*

缺省高亮方式和方言 
缺省使用适合 f95 (Fortran 95) 的高亮方式。这样的选择应该适用于绝大多数的用户，
因为 Fortran 95 是 Fortran 90 的超集，也差不多是 Fortran 77 的超集。

Fortran 源代码形式 
Fortran 9x 可以使用固定宽度的源代码，也可以使用自由形式。注意如果形式设置错
误，语法高亮也不会正确。

创建新的 Fortran 文件时，语法脚本假定使用的是固定宽度的源代码。如果你总是使用
自由形式，那么在你的 .vimrc 里，把
    :let fortran_free_source=1
放在 :syntax 命令前。如果你总是使用固定宽度格式，那么在你的 .vimrc 里，把
    :let fortran_fixed_source=1
放在 .syntax 命令前。

如果源代码的格式取决于文件扩展名，那么最方便的方法是在 ftplugin 文件里设置
fortran_free_source。见 |ftplugin|。例如，假定你所有的使用 .f90 扩展名的
Fortran 文件使用自由形式编写，而其它的则使用固定宽度，那么在你的 ftplugin 文件
里加上以下的行
    let s:extfname = expand("%:e")
    if s:extfname ==? "f90"
        let fortran_free_source=1
        unlet! fortran_fixed_source
    else
        let fortran_fixed_source=1
        unlet! fortran_free_source
    endif
注意，要使之工作，你需要在 .vimrc 文件的 "syntax on" 命令前加上 "filetype
plugin indent on" 命令。

编辑已有的 Fortran 文件时，如果定义了 fortran_free_source 变量，语法脚本假定使
用自由形式，如果定义了 fortran_fixed_source 变量，则假定使用固定宽度形式。如果
两者都没有，语法脚本检验文件的头 250 行的头 5 列。如果没有发现自由形式的迹象，
那么假定文件为固定宽度形式的源文件。这个算法应该在绝大多数情况下适用。有的情况
下，比如文件的开始有 250 行或更多完整行的注释，该脚本也许会错误地认为该
Fortran 代码使用的是固定宽度形式。如果此种情况真的发生，只要在前 250 行的头 5
列里的任何地方加上一个非注释的语句，然后保存 (:w) 并重新读入 (:e!) 文件就可以
了。

Fortran 文件里的制表键 
Fortran 标准不识别制表键。在固定宽度格式的 Fortran 源代码里，制表不是一个好主
意，因为需要固定的列边界。因此，制表被识别为错误。不过，有的程序员喜欢使用制
表。如果你的 Fortran 文件里包含制表，那么需要在 .vimrc 里使用这样的命令来设置
变量 fortran_have_tabs
    :let fortran_have_tabs=1
并把它放在 :syntax 命令之前。不幸的是，制表的使用意味着语法文件无法识别不正确
的边界。

Fortran 文件的语法折叠
如果你希望使用 foldmethod=syntax，那么你需要先使用命令设置变量 fortran_fold
    :let fortran_fold=1
来指示语法脚本为程序单元定义折叠区域。程序单元 (program unit) 包括程序语句开始
的主程序、子例程、函数子程序、块数据子程序、接口块和模块。如果你也使用如下命令
设置变量 fortran_fold_conditionals
    :let fortran_fold_conditionals=1
那么也会为 do 循环、if 块和 select case 构造定义折叠区域。如果你同时使用如下命
令设置变量 fortran_fold_multilinecomments
    :let fortran_fold_multilinecomments=1
那么还会为三行或更多连续的注释定义折叠区域。注意 定义折叠区域会使大文件变慢。

如果设置了 fortran_fold 和可能的 fortran_fold_conditionals 与/或
fortran_fold_multilinecomments，vim 会在你使用 foldmethod=syntax 时折叠文件。
两个程序单元之间的注释或空行不会被折叠，因为它们不被视作任何一个程序单元的一部
分。

更精确的 Fortran 语法 
如果使用如下命令设置变量 fortran_more_precise
    :let fortran_more_precise=1
那么语法高亮会更精确，但也更慢。特别是，能够识别 do、goto 和算术 if 语句使用的
语句标签，还有 do、if、select、或 forall 构造结尾的构造名。

非缺省的 Fortran 方言 
本语法脚本支持五种 Fortran 方言: f95、f90、f77、Lahey 子集 elf90 和 Imagine1
子集 F。

如果你使用扩展的 f77，包括常见的能被大多数 f77 编译器，包括 g77 (GNU Fortran)
所支持的构造，如 do/enddo 循环，do/while 循环和自由形式的源代码，那么也许缺省
的高亮设置就够用了。如果你使用严格的不带扩展的 f77，甚至没有自由形式的源代码或
者 MIL STD 1753 扩展等特性，那么设置 f77 方言的好处就包括，诸如 SUM 这样的名字
可以作为变量名识别，而不会作为高亮为 f9x 内建的函数；另外废弃的构造，比如
ASSIGN 语句，也不会被高亮为 todo 项目；还有，总是假定使用固定宽度的源程序。

如果你使用 elf90 或 F，设置合适的方言的优点包括，这些方言排除的 f90 特性会被高
亮为 todo 项目；还有，它们总是假定使用固定宽度的源程序。

可以通过设置变量 forran_dialect 来选择方言。可以接受的 fortran_dialect 的值是
大小写敏感的，而且必须是 "f95"、"f90"、"f77"、"elf" 或 "F" 之一。不合法的
fortran_dialect 的值被忽略。

如果你的 Fortran 文件使用相同的方言，在你的 .vimrc 文件里 syntax 命令之前设置
fortran_dialect。如果源代码的格式取决于文件扩展名，那么最方便的方法是在
ftplugin 文件里设置，见 |ftplugin|。例如，如果你使用 .f90 扩展名的所有 Fortran
文件都使用 elf 子集，那么在你的 ftplugin 文件里应该包含代码
    let s:extfname = expand("%:e")
    if s:extfname ==? "f90"
        let fortran_dialect="elf"
    else
        unlet! fortran_dialect
    endif

注意 只有在你的 .vimrc 文件的 "syntax on" 命令前加上了
"filetype plugin indent on" 命令，才能使这段代码工作。

如果文件扩展名还不能唯一确定方言，那么你需要更精细的控制。可以为每个文件定制方
言。方法是在文件的头三行内加上指令 "fortran_dialect=xx" (其中 xx=f77 或 elf 或
F 或 f90 或 f95)。例如，你较老的 .f 文件可能以扩展 f77 方言编写，但较新的那些
可能使用 F，那么你需要在后者每个文件的头三行内加上以下形式的 Fortran 注释，以
便标识
  ! fortran_dialect=F
如果两个指令都存在，F 覆盖 elf。

限制 
括号检查不能发现过少的闭括号。也不能识别 Hollerith 字符串。有些关键字可能高亮
不正确，因为 Fortran90 没有保留字。

更多关于 Fortran 的信息可见 |ft-fortran-indent| 和 |ft-fortran-plugin|。


FVWM 配 置 文 件                                *fvwm.vim* *ft-fvwm-syntax*

要使得 Vim 识别不符合模式 *fvwmrc* 或 *fvwm2rc* 的 Fvwm 配置文件，你需要在你
myfiletypes.vim 文件里放入附加适合你系统的模式。对于这些模式，你需要设置变量
"b:fvwm_version" 为 Fvwm 的主版本号，同时设置 'filetype' 选项为 fvwm。

例如，要使 Vim 识别 /etc/X11/fvwm2/ 里的所有文件为 Fvwm2 的配置文件，可以这样
设置:

  :au! BufNewFile,BufRead /etc/X11/fvwm2/*  let b:fvwm_version = 2 |
                                         \ set filetype=fvwm

如果你想让 Vim 高亮所有的合法颜色名，告诉它如何找到在你的系统上颜色数据库
(rgb.txt)。设置 "rgb_file" 指向该文件就可以了。假如你的颜色数据库在
/usr/X11/lib/X11/，加入下行

        :let rgb_file = "/usr/X11/lib/X11/rgb.txt"

到你的 .vimrc 文件里。


GSP                                             *gsp.vim* *ft-gsp-syntax*

GSP 页面的缺省色彩风格由 |html.vim| 定义，而 Java 代码 (在 Java 标签里或反引号
之间的内含代码) 的颜色由 |java.vim| 定义。 |html.vim| 里定义的以下 HTML 组在这
里被重新定义，以配合高亮的内含 (inline) Java 代码:

    htmlString
    htmlValue
    htmlEndTag
    htmlTag
    htmlTagN

多数你看到内含 Java 代码的地方，高亮应该没问题，但在一些特殊情况下可能有问题。
要加入其它可包含内含 Java 代码而高亮不正确的 HTML 组，只要从 |html.vim| 里把你
想要的行复制出来，并在 contains 子句里加上 gspJava 就可以了。

反引号里的内含 Java 使用 htmlError 组高亮，使之更易看清。


GROFF                                           *groff.vim* *ft-groff-syntax*

groff 语法文件是 |nroff.vim| 的包装，见该标题下的说明参阅使用和配置的示例。提
供这个包装的目的是通过 |modeline| 或个人的文件类型文件 (见 |filetype.txt|) 来
设置文件类型，从而设置 groff 专用的语法扩展。


HASKELL                      *haskell.vim* *lhaskell.vim* *ft-haskell-syntax*

Haskell 语法文件支持普通的 Haskell 代码和文学的 (literate) Haskell 代码，后者
包括 Bird 风格和 Tex 风格。Haskell 语法高亮也能高亮 C 预处理指令。

如果你想高亮定界符 (适用于浅色背景)，在 .vimrc 里加上:
        :let hs_highlight_delimiters = 1
要把 True 和 False 识别为关键字而不是普通的标识符，加上:
        :let hs_highlight_boolean = 1
要把基本类型的名字识别为关键字:
        :let hs_highlight_types = 1
要把更多相对常用的类型识别为关键字:
        :let hs_highlight_more_types = 1
如果想高亮调试函数的名字，在你的 .vimrc 里加上:
        :let hs_highlight_debug = 1

Haskell 语法高亮也高亮 C 预处理指令，但非法的 # 开始的指令被标记为错误。这和
Haskell 的操作符语法有冲突，因为它们可能会用 # 开始。如果你想高亮这些为操作符
而不是错误，在 .vimrc 里加入:
        :let hs_allow_hash_operator = 1

文学的 Haskell 代码的语法高亮会试图自动猜测你的文学 Haskell 代码是否包含 Tex
标记，并相应地高亮 Tex 构造或什么也不做。要在全局改变此行为，在你的 .vimrc 文
件里放上
        :let lhs_markup = none
就可完全关闭高亮。或者
        :let lhs_markup = tex
强制使用 Tex 标记风格的高亮。更灵活的方法是使用该变量的局部于缓冲区的版本，例
如
        :let b:lhs_markup = tex
会强制为特定的缓冲区使用 TeX 高亮。必须在该缓冲区打开语法高亮或者载入文件前设
置。


HTML                                            *html.vim* *ft-html-syntax*

HTML 文件里，标签的色彩方案工作方式如下。

开放标签的 <> 和关闭标签的 </> 的颜色不同。这是有意的！开放标签使用 'Function'
色，而关闭标签使用 'Type' 色 (察看 syntax.vim 了解它们是如何为你定义的)。

已知的标签名使用 C 语句 (Statement) 的色彩。未知的标签名分别和相应的 <> 或 </>
颜色相同，以便纠错。

注意 这同样适用于参数 (或属性) 名。已知的属性名和未知的颜色不同。

一些 HTML 标签用于改变文本的显示。html.vim 语法色彩文件识别以下的标签，并相应
地改变普通文本的显示方式: <B> <I> <U> <EM> <STRONG> (<EM> 是 <I> 的别名，而
<STRONG> 是 <B> 的别名)，<H1> - <H6>，<HEAD>，<TITLE> 和 <A> (<A> 必须在作为链
接，即包含了 href，才会如此。如 <A href="somfile.html">)。

如果你想改变文本显示的方式，必须重定义以下的语法组:

    - htmlBold
    - htmlBoldUnderline
    - htmlBoldUnderlineItalic
    - htmlUnderline
    - htmlUnderlineItalic
    - htmlItalic
    - htmlTitle 设定标题
    - htmlH1 - htmlH6 设定标题头部 (header) 的文本

要使得重定义能够工作，你必须重定义所有的组，最后两组 (htmlTitle 和 htmlH[1-6]
可选) 可以除外。在你的 vimrc (这是根据初始化时读入文件的顺序) 里定义下面的变量

        :let html_my_rendering=1

要想看一个例子，下载 http://www.fleiner.com/vim/download.html 的 mysyntax.vim
文件。

在你的 vimrc 文件里加上这行，可以屏蔽这种显示方式:
        :let html_no_rendering=1

HTML 注释相当特别 (详情见 HTML 的参考文档)，此语法高亮方案会高亮所有的错误。不
过，如果你喜欢不太正确 (以 <!-- 开始并以 --!> 结束) 的风格，可以定义
        :let html_wrong_comments=1

HTML 文档的内嵌 (embedded) JavaScript 和 Visual Basic 使用 'Special' 高亮，而
其中的语句、注释、字符串等使用标准的编程语言的颜色。注意 现在只支持 JavaScript
和 Visual Basic，还没有加入其它的脚本语言。

内嵌和内含 (inline) 的层叠样式表 (CSS) 也被高亮。

有多种 html 预处理器语言，html.vim 的编写方式使得包含它非常容易。要想这么做，
只要在相应语言的语法高亮文件里加入如下两行 (该例子来自 asp.vim 文件) 就可以了:

    runtime! syntax/html.vim
    syn cluster htmlPreproc add=asp

现在你只需要把所有包含预处理语言的区域项目加到 htmlPreproc 簇里就可以了。


HTML/OS (Aestiva 提供)                          *htmlos.vim* *ft-htmlos-syntax*

HTML/OS 的色彩高亮方案工作方式如下:

缺省为函数和变量名使用相同的颜色，因为 VIM 并不为 Function 和 Identifier 指定
不同的颜色。要改变这一点 (如果你希望函数名能用不同的颜色加以识别的话，建议使
用)，你需要在 ~/.vimrc 里加入下行:
  :hi Function term=underline cterm=bold ctermfg=LightGray

当然如果你愿意，ctermfg 可以使用别的颜色。

HTML/OS 碰到的另一个问题是没有特殊的指示 HTML/OS 编码的文件类型。打开文件并用
下面的方法打开 HTML/OS 语法，你就可以改变这一点:
  :set syntax=htmlos

最后要提醒一下，启动 HTML/OS 代码块的打开和关闭字符序列分别是 << 或 [[ 和 >>
或 ]]。


IA64                            *ia64.vim* *intel-itanium* *ft-ia64-syntax*

为 Intel Itanium 64 汇编语言提供高亮。|asm.vim| 说明如何识别该文件类型。

要识别 *.inc 文件为 IA64，在你的 .vimrc 文件里加入这行:
        :let g:filetype_inc = "ia64"


INFORM                                          *inform.vim* *ft-inform-syntax*

Inform 高亮包含 Inform 库提供的符号，因为多数程序大量使用它们。如果不希望高亮
这些库里的符号，在你的 vim 启动文件里加入:
        :let inform_highlight_simple=1

缺省假定 Inform 程序面向 Z 机器。并适当地高亮 Z 机器的汇编语言符号。如果期望程
序面向 Glulx/Glk 环境，你需要在启动文件的序列中加入:
        :let inform_highlight_glulx=1

这样就只高亮 Glulx 操作码，并把 glk() 加到高亮的系统函数集合里。

Inform 编译器遇到特定已废弃的关键字时，会标记它们为错误。通常，Vim 也把这些关
键字标为错误。如果不想高亮这些错误，你必须在启动文件的序列中加入:
        :let inform_suppress_obsolete=1

缺省的高亮设置符合编译器版本 6.30 和库版本 6.11 的语言特性。如果你使用较老的
Inform 开发环境，可能需要在启动文件的序列中加入:
        :let inform_highlight_old=1

IDL                                                     *idl.vim* *idl-syntax*

IDL (Interface Definition Language，接口定义语言) 文件用于定义 RFC 调用。
Microsoft 的领地里也用来定义 COM 接口和调用。

IDL 的结构足够简单，所以可以分析完整语法，而不需要一些启发式的猜测。结果很大，
甚至可能有些重复工作，但看来能用了。

这里有一些 Microsft 的 idl 文件扩展。有些可以通过 idl_no_ms_extensions 关闭。

更复杂的扩展可以通过定义 idl_no_extensions 来关闭。

变量                            效果 

idl_no_ms_extensions            关闭一些 Microsoft 专用的扩展
idl_no_extensions               关闭复杂扩展
idlsyntax_showerror             显示 IDL 错误 (可能过于侵略性，但很有用)
idlsyntax_showerror_soft        使缺省的错误颜色柔和一些


JAVA                                            *java.vim* *ft-java-syntax*

java.vim 语法高亮文件提供若干选项:

在 Java 1.0.2 里，小括号里不可能有大括号，所以这被标识为错误。但从 Java 1.1 开
始，这是合法的 (无名类的使用)，因而它不再标为错误。如果你喜欢旧的方式，在 vim
启动文件里加入下行:
        :let java_mark_braces_in_parens_as_errors=1

所有 java.lang.* 的标识符在所有的类里都是可见的。要高亮它们，可用:
        :let java_highlight_java_lang_ids=1

如果你从 http://www.fleiner.com/vim/download.html 下载 javaid.vim 脚本，你也可
以高亮大多数标准 java 包里的标识符。
如果你只想高亮特定包里的标识符，比如说 java.io，可以用:
        :let java_highlight_java_io=1
察看 javaid.vim 文件，可以得到它支持的所有包的列表。

函数名不会高亮，因为找到函数的方法取决于你如何写 Java 代码。语法文件知道两种可
以高亮函数的方法:

如果你的函数定义总是使用一个制表、8 个空格或者 2 个空格的缩进，可以设置
        :let java_highlight_functions="indent"
不过，如果你遵循 Java 指南里函数和类的命名规则 (关于大小写)，就可以用
        :let java_highlight_functions="style"
如果两个选项都不合适，但你仍然期望高亮函数声明，修改 java.vim 里的定义或者创建
你自己的 java.vim。你自己的版本应该包含原来的版本，并增加高亮函数的代码。

Java 1.1 里，只应该用函数 System.out.println() 和 System.err.println() 来进行
调试。所以你可以用不同的方式高亮调试语句。要这么做，你必须在启动文件里加上以下
定义:
        :let java_highlight_debug=1
结果那些语句会被高亮为 'Special' 字符序列。如果你喜欢用不同的方式分别高亮，必
须为以下各组定义新的高亮:
    Debug、DebugSpecial、DebugString、DebugBoolean、DebugType
它们分别用来高亮语句本身，调试字符串里的特殊字符、字符串、布尔常量和类型
(this，super)。我本人喜欢给语句设置别的背景。

为了帮助你编写在 Java 和 C++ 之间容易移植的代码，Java 程序里的所有的 C++ 关键
字被标为错误。不过，如果你经常使用，可以在 .vimrc 文件里定义如下变量:
        :let java_allow_cpp_keywords=1

Javadoc 是一个程序，它接受特殊的 Java 程序文件里的注释，并创建 HTML 页面。标准
的配置会以类似于 HTML 文件 (见 |html.vim|) 方式高亮该 HTML 代码，你甚至可以在
代码里加入 Javascript 和 CSS (见下)。但有四处不同:
  1. 标题 (第一个后面有若干空白跟随的 '.' 或第一个 '@' 之前的所有字符) 使用不
     同的颜色 (要改变其颜色，修改 CommentTitle 组)。
  2. 文本使用 'Comment' 高亮。
  3. HTML 注释使用 'Special' 高亮。
  4. 特殊的 Javadoc 标签 (@see、@param、...) 用 Special 高亮。 而 ( @see、
     @param、@exception 的)参数则使用 Function 高亮。
要关闭该特性，在你的启动文件里加入该行:
        :let java_ignore_javadoc=1

如果你使用上述的特殊 Javadoc 注释高亮方式，你也可以打开 Javascript、Visual
Basic 脚本和内嵌 CSS (样式表) 的特殊高亮。只有在你实际有包含 Javascript 或内
嵌 CSS 的 Javadoc 注释时，这才有意义。要使用的选项分别是
        :let java_javascript=1
        :let java_css=1
        :let java_vb=1

要以不同的颜色高亮嵌套的括号，分别定义 javaParen、javaParen1 和 javaParen2 的
颜色。比如用
        :hi link javaParen Comment
或
        :hi javaParen ctermfg=blue guifg=#0000ff

如果你注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正的话，尝试设置
"java_minlines" 内部变量为较大的值:
        :let java_minlines = 50
这使得语法同步在第一个显示行之前的 50 行开始。缺省值为 10。使用较大的值的缺点
是重画会变慢。


LACE                                            *lace.vim* *ft-lace-syntax*

Lace (Language for Assembly of Classes in Eiffel，Eiffel 类整合语言) 对大小写
不敏感，但风格指南不是这么建议的。如果你喜欢对大小写不敏感的高亮，在启动文件里
定义 vim 变量 'lace_case_insensitive':
        :let lace_case_insensitive=1


LEX                                             *lex.vim* *ft-lex-syntax*

Lex 使用强力攻击 (brute-force) 的方式进行同步，因为 "^%%$" 段定界符没有提供任
何关于后续段的提示。因而，如果用户有同步问题的话 (比如使用很大的 lex 文件)，
他/她可以尝试改变
        :syn sync minlines=300
的值。


LISP                                            *lisp.vim* *ft-lisp-syntax*

Lisp 语法高亮提供两个选项:

        g:lisp_instring : 如果存在，那么 "(...)" 字符串会被高亮，就像字符串里
                          的内容是 Lisp 代码一样。对 AutoLisp 有用。
        g:lisp_rainbow  : 如果存在且非零，那么不同的括号层次产生不同的高亮。

g:lisp_rainbow 选项为小括号和反引号提供 10 层不同的色彩。因为色彩层次的数量关
系，不同于非 rainbow (彩虹) 方式，rainbow 模式直接使用 ctermfg 和 guifg 指定高
亮色彩，而回避了标准的使用高亮组的色彩方案控制。实际使用的高亮值仍然取决于深/
浅设置 (见 |'bg'|)。


LITE                                            *lite.vim* *ft-lite-syntax*

lite 语法高亮有两个选项。

如果你喜欢字符串里的 SQL 语法高亮，使用:

        :let lite_sql_query = 1

同步的缺省 minlines 为 100。如果你喜欢别的值，可以把 "lite_minlines" 设为你想
要的值。例如:

        :let lite_minlines = 200


LPC                                             *lpc.vim* *ft-lpc-syntax*

LPC 代表一种简单又节省内存的语言: Lars Pensj| C。LPC 的文件名通常是 *.c。把这
些文件识别为 LPC 会惹恼那些只用 C 程序的用户。如果你想使用 Vim 的 LPC 语法，在
你的 .vimrc 文件里设置变量:

        :let lpc_syntax_for_c = 1

如果这对某些特殊的 C 或 LPC 文件不能工作，用模式行。在 LPC 文件里:

        // vim:set ft=lpc:

对于被识别为 LPC 的 C 文件:

        // vim:set ft=c:

如果你不想设置此变量，在_每个_ LPC 文件里使用模式行。

LPC 有若干实现，我们打算支持最常用的实现。这里缺省的 LPC 语法基于 MudOS 系列。
对于 MudOS v22 和以前的版本。你应该关闭合适的修饰符，它也会把 v22 之后的新的
efun 认定为非法。如果你使用最新的 MudOS 版本，不要设置该变量:

        :let lpc_pre_v22 = 1

对于 LpMud 3.2 系列的 LPC:

        :let lpc_compat_32 = 1

对于 LPC4 系列的 LPC:

        :let lpc_use_lpc4_syntax = 1

对于 uLPC 系列的 LPC:
uLPC 是为 Pike 开发的，所以你应该使用 Pike 的语法，而且源文件应该是 *.pike。


LUA                                             *lua.vim* *ft-lua-syntax*

该语法文件可用于 Lua 4.0、Lua 5.0 或 Lua 5.1 (缺省)。用全局变量 lua_version 和
lua_subversion 可以选择其中一个版本。例如，如果要激活 Lua 4.0 语法高亮，用:

        :let lua_version = 4

如果你使用 Lua 5.0，用:

        :let lua_version = 5
        :let lua_subversion = 0

要恢复 Lua 5.1 的高亮:

        :let lua_version = 5
        :let lua_subversion = 1


MAIL                                            *mail.vim* *ft-mail.vim*

Vim 高亮 email 的所有标准元素 (信头、签名、引用文本和 URL / email 地址)。要符
合标准的习惯，签名应该以 "--" 开头，跟随可选的若干空格并以回车结束的一行开始。

Vim 把 ']'、'}'、'|'、'>' 或者有 '>' 跟随的单词开始的行高亮为引用文本。不过，
只有在引用文本用 '>' 的方式引用 (后面可跟一个可选的空格)，Vim 才把把该文本里的
信头和签名高亮为引用文本。

mail.vim 缺省从第一个显示行之前的 100 行开始同步语法。如果你的机器很慢，而且通
常处理的 email 的信头不长，你可以把它设为较小的值:

    :let mail_minlines = 30


MAKE                                            *make.vim* *ft-make-syntax*

Makefile 里，命令通常被高亮以便你发现错误。不过，如果你觉得颜色太多了，可以这
样关闭此特性:

        :let make_no_commands = 1


MAPLE                                           *maple.vim* *ft-maple-syntax*

Waterloo Maple Inc 的 Maple V 支持符号代数。该语言支持很多函数包，用户可以选择
性地装载。如果用户愿意，可以高亮 Maple V release 4 提供的标准包函数。用户可以
在 .vimrc 文件里加入:

        :let mvpkg_all= 1

来高亮所有的包里的函数。用户也可以通过从下表选择变量/包来挑选一个子集，并在
.vimrc 文件里 (在执行 $VIMRUNTIME/syntax/syntaxvim 之前) 设置挑选的变量为 1 就
可以了。

                        Maple V 包函数选择器表
  mv_DEtools     mv_genfunc     mv_networks     mv_process
  mv_Galois      mv_geometry    mv_numapprox    mv_simplex
  mv_GaussInt    mv_grobner     mv_numtheory    mv_stats
  mv_LREtools    mv_group       mv_orthopoly    mv_student
  mv_combinat    mv_inttrans    mv_padic        mv_sumtools
  mv_combstruct  mv_liesymm     mv_plots        mv_tensor
  mv_difforms    mv_linalg      mv_plottools    mv_totorder
  mv_finance     mv_logic       mv_powseries


MATHEMATICA             *mma.vim* *ft-mma-syntax* *ft-mathematica-syntax*

自动假设空白的 *.m 文件为 Matlab 文件，除非你在 .vimrc 里指定了:

        let filetype_m = "mma"


MOO                                             *moo.vim* *ft-moo-syntax*

如果你在表达式里使用 C 风格的注释但发现它影响了高亮，可以尝试使用扩展的 (会变
慢！) C 风格注释的匹配:

        :let moo_extended_cstyle_comments = 1

要关闭字符串里的代词替换 (pronoun substitution) 模式高亮:

        :let moo_no_pronoun_sub = 1

要关闭正规表达式 '%|' 操作符和字符串里匹配的 '%(' 和 '%)' 所用的高亮:

        :let moo_no_regexp = 1

可以识别不匹配的双引号并高亮为错误:

        :let moo_unmatched_quotes = 1

要高亮内建的属性 (.name、.location、.programmer 等):

        :let moo_builtin_properties = 1

可以识别未知的内建函数并高亮为错误。如果你使用该选项，应该把自己的扩展加到
mooKnownBuiltinFunction 组里。要打开该选项:

        :let moo_unknown_builtin_functions = 1

把 sprintf() 加到已知内建函数列表的例子:

        :syn keyword mooKnownBuiltinFunction sprintf contained


MSQL                                            *msql.vim* *ft-msql-syntax*

msql 语法高亮有两个选项。

如过你希望高亮字符串里的 SQL 语法，使用:

        :let msql_sql_query = 1

同步的 minlines 缺省为 100。如果你喜欢别的值，可以设置 "msql_minlines" 为你所
希望的值。例如:

        :let msql_minlines = 200


NCF                                             *ncf.vim* *ft-ncf-syntax*

NCF 语法高亮有一个选项。

如果你想把不能识别的 (依据 ncf.vim) 语句高亮为错误，使用:

        :let ncf_highlight_unknowns = 1

如果你不想高亮它们为错误，留着该变量不设置就可以了。


NROFF                                           *nroff.vim* *ft-nroff-syntax*

nroff 语法文件可直接用于 AT&T n/troff 而无需修改。如果要使用 GNU groff，你需要
在使用之前激活语法文件里的一些附加特性。

例如，Linux 和 BSD 的发布版本使用 groff 作为缺省的文本处理包。要激活 groff
附加的语法高亮特性，在你的启动文件里加入以下选项:

  :let b:nroff_is_groff = 1

Groff 和老的 AT&T n/troff 不同，后者还可以在 Solaris 找到。Groff 宏和请求名可
以超过 2 个字符，而且有语言基本命令之外的扩展。例如，AT&T troff 里你可以用请求
\(yr 得到 2 位数的年份。groff 里为了照顾兼容性，可以使用相同的请求，你也可以直
接使用 groff 本身的宏: \[year]。宏请求可以超过 2 个字符，比如，GNU mm 接受
".VERBON" 和 ".VERBOFF" 请求，以创建 verbatim (不作转换的) 环境。

要得到 g/troff 能给出的最好的输出，需要遵循一些关于空格和标点的简单的规则。

1. 不要在行尾留空白。

2. 在句尾的句号、感叹号等之后留且只留一个空格。

3. 由于下面的原因，最好在所有的句号之后立即回车。

这些不寻常的提示的背后原因是，如果你不遵循上面的这些规则，g/n/troff 使用的换行
算法很容易弄错。

和 TeX 不同，troff 逐行而不是逐段填充文本。此外，它没有 glue (可伸缩的距离) 或
stretch 的概念，所有的水平和垂直空白输入都直接成为输出。

因此你必须小心，不要在句子之间留下比你在最终文档想要的更多的空白。因此，通常在
每个标点符号之后都立即插入一个回车。如果你想要最终处理过的文本 "对齐"，需要在
输入文本里维持常规的空间。要把行尾的空格和标点之后两个或更多的空格标为错误，可
用:

  :let nroff_space_errors = 1

另一个检测额外的空格和其它错误的技术会影响你文件的正确排版。这个方法是在你的配
置文件里定义语法组 "nroffDefinition" 和 "nroffDefSpecial" 显眼的高亮定义。例
如:

  hi def nroffDefinition term=italic cterm=italic gui=reverse
  hi def nroffDefSpecial term=italic,bold cterm=italic,bold
                         \ gui=reverse,bold

如果你想像段标记符那样方便地浏览源文件里的预处理项目，可以在 .vimrc 文件里激活
以下选项:

        let b:preprocs_as_sections = 1

还有，语法文件为 ms 包里设置带缩进的 (exdented) 段落宏 (.XP) 增加了一个附加的
段标记符。

最后，有一个 |groff.vim| 语法文件，可以基于每个文件或，缺省情况下，在全局打开
groff 的语法高亮。


OCAML                                           *ocaml.vim* *ft-ocaml-syntax*

OCaml 语法文件处理带以下后缀的文件: .ml、.mli、.mll 和 .mly。设置以下变量

        :let ocaml_revised = 1

你就可以切换标准的 OCaml 语法为 camlp4 预处理器支持的改进的语法。设置变量

        :let ocaml_noend_error = 1

防止把 "end" 高亮为错误，这可用于源程序包含很长的结构而 Vim 不再能保持同步的场
合。


PAPP                                            *papp.vim* *ft-papp-syntax*

PApp 语法文件处理 .papp 文件和，在一定程度上，.pxml 和 .pxsl 文件。它们都是
perl / xml / html / 其它格式 的混合，并使用 xml 作为顶层的文件格式。缺省，所有
phtml 和 pxml 段里的内容都被处理为包含内嵌预处理器命令的字符串。如果你在启动文
件里设置变量:

        :let papp_include_html=1

它就会试图语法高亮 pthml 段里的 html 代码，但这相对较慢，而且对于有效的编辑未
免色彩太鲜艳了些 ;)

可以在 http://papp.plan9.de 找到最新的 papp.vim 语法文件的版本。


PASCAL                                          *pascal.vim* *ft-pascal-syntax*

匹配 "*.p" 的文件可以是 Progress 或者 Pascal 的。如果自动检测对你不适用，或者
你从来不编辑 Progress，在启动 vimrc 里加入:

   :let filetype_p = "pascal"

Pascal 语法文件被扩展，以支持 Turbo Pascal、Free Pascal 编译器和 GNU Pascal 编
译器的一些扩展。也支持 Delphi 的关键字。缺省打开 Turbo Pascal 7.0 特性。如果你
只想使用标准的 Pascal 关键字，在你的启动文件里加入下行:

   :let pascal_traditional=1

要打开 Delphi 专用的构造 (比如单行注释、关键字、等等):

   :let pascal_delphi=1


pascal_symbol_operator 选项控制符号 (symbol) 操作符，如 +、* 等，是否使用
Operator 的色彩高亮。要给符号的操作符加上颜色，在你的启动文件里加入下行:

   :let pascal_symbol_operator=1

有些函数缺省是高亮的。要关闭:

   :let pascal_no_functions=1

另外，一些编译器有专门的变量。除了 pascal_delphi 以外，还有 pascal_gpc 和
pascal_fpc。缺省试图匹配 Turbo Pascal 的扩展。

   :let pascal_gpc=1

或

   :let pascal_fpc=1

要确保字符串在一行内定义，你可以定义 pascal_one_line_string 变量。

   :let pascal_one_line_string=1

如果你不喜欢 <Tab> 字符，你可以设置 pascal_no_tabs 变量。制表会被高亮为 Error。

   :let pascal_no_tabs=1



PERL                                            *perl.vim* *ft-perl-syntax*

perl 的语法高亮有一些可用的选项。

如果你使用 POD 文件或者 POD 段，可能会:

        :let perl_include_pod = 1

要减低分析的复杂度 (同时提高了效率)，你可以关闭变量名和内容的分析过程的两个元
素。

要使变量和函数名里对包的引用与名字的其它部分不区别显示 (如 '$PkgName::VarName'
里的 'PkgName::'):

        :let perl_no_scope_in_variables = 1

(Vim 6.x 里相反，用 "perl_want_scope_in_variables" 打开区别显示。)

如果你不想分析复杂的结构，比如 '@{${"foo"}}':

        :let perl_no_extended_vars = 1

(Vim 6.x 里相反，用 "perl_extended_vars" 打开此项分析。)

你可以改变颜色字符串。缺省，字符串和 qq 等变形会象下面第一行那样高亮。如果你设
置了变量 perl_string_as_statement，那么就像下面第二行那样高亮。
   "hello world!"; qq|hello world|;
   ^^^^^^^^^^^^^^NN^^^^^^^^^^^^^^^N       (unlet perl_string_as_statement)
   S^^^^^^^^^^^^SNNSSS^^^^^^^^^^^SN       (let perl_string_as_statement)

(^ = perlString、S = perlStatement、N = 什么都没有)

同步有三个选项。前两个关掉一些激活同步的方法，而只有在无法正确工作的时候你才需
要它们。比如，如果滚动时突然全屏的颜色发生改变，那么你应该尝试改变并关闭其中的
某一个。如果你可以发现哪一行导致这种错误，请告诉我。

大致上，其中一个在 "^\s*sub\s*" 上激活，另一个则在 "^[$@%]" 上。

        :let perl_no_sync_on_sub
        :let perl_no_sync_on_global_var

下面，你还可以设置 VIM 往前找语法高亮的起始点的最大距离。

        :let perl_sync_dist = 100

如果你想要在 perl 里使用折叠，设置 perl_fold:

        :let perl_fold = 1

如果你想折叠 if 等语句块，设置如下:

        :let perl_fold_blocks = 1

要避免设置 perl_fold 时对 package (包) 和 sub (例程) 进行折叠，设置合适的变量:

        :unlet perl_nofold_packages
        :unlet perl_nofold_subs



PHP3 和 PHP4            *php.vim* *php3.vim* *ft-php-syntax* *ft-php3-syntax*

[注意: 以前这被称为 "php3"，但因为现在这也支持 php4，它被改名为 "php"]

php 的语法高亮支持以下选项。

如果你喜欢字符串里的 SQL 语法高亮:

  let php_sql_query = 1

要高亮 Baselib 方法:

  let php_baselib = 1

打开字符串里的 HTML 语法高亮:

  let php_htmlInStrings = 1

使用旧的色彩风格:

  let php_oldStyle = 1

打开 ASP 风格的短标签的高亮:

  let php_asp_tags = 1

关闭短标签:

  let php_noShortTags = 1

要高亮外层 ] 或 ) 的错误:

  let php_parent_error_close = 1

要在有打开的 ( 和 [ 但没有相应的结束符号的情况下跳过 php 结束标签:

  let php_parent_error_open = 1

打开类和函数的折叠:

  let php_folding = 1

选择同步方法:

  let php_sync_method = x

x = -1 使得同步以搜索方法进行 (缺省)，
x > 0 使得同步至少往回 x 行，
x = 0 使得同步从头开始。


PLAINTEX                                *plaintex.vim* *ft-plaintex-syntax*

TeX 是排版语言，而 plaintex 是代表 Tex 的 "平凡" 变种的文件类型。如果你想
*.tex 文件被识别为平凡 TeX，见 |ft-tex-plugin|。

此语法文件有以下选项

        let g:plaintex_delimiters = 1

如果你想高亮方括号 "[]" 和大括号 "{}" 的话。


PPWIZARD                                        *ppwiz.vim* *ft-ppwiz-syntax*

PPWizard 是 HTML 和 OS/2 INF 文件的预处理器。

该语法文件有如下选项:

- ppwiz_highlight_defs : 决定 PPWizard 定义的高亮模式。可能值是

  ppwiz_highlight_defs = 1 : PPWizard #define 语句保留其内容的色彩 (比如，
    PPWizard 的宏和变量)

  ppwiz_highlight_defs = 2 : 预处理器 #define 和 #evaluate 语句使用单色显示，
    除了行继续符以外

  缺省 ppwiz_highlight_defs 的设置为 1。

- ppwiz_with_html : 如果该值为 1 (缺省)，高亮按本义出现的 HTML 代码；如果为
  0，把 HTML 代码当成普通的文本。


PHTML                                           *phtml.vim* *ft-phtml-syntax*

phtml 语法高亮有两个选项。

如果你喜欢字符串里的 SQL 语法高亮，使用:

        :let phtml_sql_query = 1

同步的 minlines 缺省为 100。如果你喜欢别的值，可以设置 "phtml_minlines" 为你所
希望的值。例如:

        :let phtml_minlines = 200


POSTSCRIPT                              *postscr.vim* *ft-postscr-syntax*

PostScript 的高亮有若干选项。

首先决定是 PostScript 语言的哪个版本要高亮。目前定义了三个语言版本。Level 1 是
原始和基础的版本，包括所有的 Level 2 发布之前的扩展。Level 2 是最常用的版本，
包括 Level 3 发布之前它自身的所有扩展。Level 3 是目前支持的最高版本。你可以
这样定义 postscr_level 变量，以选择需要高亮的 PostScript 的语言级别:

        :let postscr_level=2

如果该变量没有定义，缺省值为 2 (Level 2)，因为这是目前最常用的版本。

注意，不是所有的 PS 解释器都支持某一特定语言级别的所有语言特性。特别是，PS 文
件开头的 %!PS-Adobe-3.0 并_不_意味着使用的 PostScript 是 Level 3 的
PostScript！

如果你使用 Display PostScript，可以这样定义 postscr_display 变量来包含 Display
PS 语言特性的高亮:

        :let postscr_display=1

如果你使用 Ghostscript，可以这样定义 postscr_ghostscript 变量来包含
Ghostscript 特有的语言特性的高亮:

        :let postscr_ghostscript=1

PostScript 是一个很大的语言，有许多预定义的元素。尽管包含所有这些元素的高亮很
有用，在较慢的机器上这会使得 Vim 变慢。为了使得对机器更友善，缺省不给字体名和
字符编码高亮。如果你不是显式地打开它们，应该没有问题。如果你确实想看到它们的高
亮，可以设置下面之中的一个或两个变量:

        :let postscr_fonts=1
        :let postscr_encodings=1

关于 and、or 和 not 的高亮有一个风格的选项。PostScript 里，这些操作符的函数取
决于它们操作数的类型 - 如果操作数都是布尔型，它们是逻辑操作符。如果是整数，它
们是二进制操作符。如果二进制和布尔型操作符高亮方式不同，它们可以用任何一种方式
高亮。缺省它们被作为逻辑操作符。如果这样定义 postscr_andornot_binary 变量，它
们可以用二进制操作符方式进行高亮:

        :let postscr_andornot_binary=1


                        *ptcap.vim* *ft-printcap-syntax*
PRINTCAP + TERMCAP      *ft-ptcap-syntax* *ft-termcap-syntax*

该语法文件适用于 printcap 和 termcap 数据库。

要使得 Vim 识别不匹配模式 "printcap" 或 "termcap" 的 printcap/termcap 文件，你
需要在 |myfiletypefile| 文件里定义合适你的系统的附加的模式。对这些模式，你必须
设置变量 "b:ptcap_type" 为 "print" 或 "term"，然后设置 'filetype' 选项为
ptcap。

比如，要使得 Vim 识别 /etc/termcaps/ 里的所有文件为 termcap 文件，加入下行:

   :au BufNewFile,BufRead /etc/termcaps/* let b:ptcap_type = "term" |
                                       \ set filetype=ptcap

如果你注意到往回滚动时高亮有问题，但 CTRL-L 又可以修正的时候，尝试设置
"ptcap_minlines" 内部变量为一个大的数字:

   :let ptcap_minlines = 50

(缺省为 20 行。)


PROGRESS                                *progress.vim* *ft-progress-syntax*

匹配 "*.w" 的文件可以是 Progress 或者 cweb 的。如果自动识别对你无效，或者你从
来不编辑 cweb，在你的启动 vimrc 里加入:
   :let filetype_w = "progress"
这同样适用于可为汇编文件的 "*.i" 和可为 Pascal 文件的 "*.p"。如果你不使用汇编
和 Pascal，你可以这么用:
   :let filetype_i = "progress"
   :let filetype_p = "progress"


PYTHON                                          *python.vim* *ft-python-syntax*

有四个选项可以控制 Python 的语法高亮。

要高亮数值:
        :let python_highlight_numbers = 1

要高亮内建函数:
        :let python_highlight_builtins = 1

要高亮标准例外:
        :let python_highlight_exceptions = 1

要高亮行尾的空白还有空格和制表的混合:
        :let python_highlight_space_errors = 1

如果你想要所有可能的 Python 高亮 (等同于设置以上的所有选项):
        :let python_highlight_all = 1


QUAKE                                           *quake.vim* *ft-quake-syntax*

Quake 语法定义应可用于多数基于某个 Quake 引擎的 FPS (First Person Shooter)。不
过，在相关的三个游戏 (Quake、Quake 2 和 Quake 3 Arena) 中，命令的名字略有不
同。所以，语法定义检查三个全局变量是否存在，从而使用户可以指定他们的文件里哪些
命令是合法的。这三个变量的设置有如下效果。

设置使得高亮命令只适用于 Quake:
        :let quake_is_quake1 = 1

设置使得高亮命令只适用于 Quake 2:
        :let quake_is_quake2 = 1

设置使得高亮命令只适用于 Quake 3 Arena:
        :let quake_is_quake3 = 1

组合这三个变量的使用也是可以的，不过高亮的命令也许比你的游戏里实际可用的命令要
多。


READLINE                                *readline.vim* *ft-readline-syntax*

readline 库主要由 BASH 外壳使用，在已有的命令和选项的基础上，它又增加了不少。
要高亮这些附加的命令和选项，可以把这行加到你的 |vimrc| 里，或者在载入使用
readline 语法的文件前，在命令行输入:
        let readline_has_bash = 1

这使得 BASH (2.05a 和其后的版本，也包括部分以前的) 增加的命令被高亮。


REXX                                            *rexx.vim* *ft-rexx-syntax*

如果你注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正的话，尝试设置
"rexx_minlines" 内部变量为较大的值:
        :let rexx_minlines = 50
这使得语法同步在第一个显示行之前的 50 行开始。缺省值为 10。使用较大的值的缺点
是重画会变慢。


RUBY                                            *ruby.vim* *ft-ruby-syntax*

Ruby 语法高亮有若干选项。

缺省，"end" 关键字根据它关闭的块对应的打开语句设定颜色。尽管很有用，该特性很消
耗资源: 如果你发现重画变慢 (或者你所在的终端色彩支持不好)，你可能想关闭该特
性，只要定义 "ruby_no_expensive" 变量即可:

        :let ruby_no_expensive = 1

此时，所有的控制关键字使用相同的颜色。

如果你想使用该特性，但注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正
的话，尝试设置 "ruby_minlines" 变量超过 50:

        :let ruby_minlines = 100

理想的话，该值应该足够大，使得最大的类或模块能够得到处理。

特殊标识符的高亮可以通过定义 "ruby_no_identifiers" 来关闭:

        :let ruby_no_identifiers = 1

这会防止标识符 "ConstantName" (常数)、"$global_var" (全局变量)、"@@class_var"
(类变量)、"@instance_var" (实例变量)、"| block_param |" (块参数)、和 ":symbol"
(符号) 的特殊高亮。

Kernel、Module 和 Object 里的主要方法缺省都是高亮的。可以通过定义
"ruby_no_special_methods" 关闭之:

        :let ruby_no_special_methods = 1

这会禁止重要方法的高亮，比如 "require"、"attr"、"private"、"raise" 和 "proc"。

可以通过定义 "ruby_space_errors" 打开空白错误的高亮:

        :let ruby_space_errors = 1

会高亮行尾的空白，而空格后的制表也被认为是错误。通过定义
"ruby_no_trail_space_error" 和 "ruby_no_tab_space_error"，可以进一步限定。这两
个变量分别忽略行尾空白和空格之后的制表。

定义 "ruby_fold" 可以打开折叠:

        :let ruby_fold = 1

会把 'foldmethod' 选项设为 "syntax"，并且提供了类、模块、方法、代码块、here 文
档和注释的折叠。

SCHEME                                          *scheme.vim* *ft-scheme-syntax*

缺省只高亮 R5RS 关键字并进行适当的缩进。

如果定义  b:is_mzscheme 或 g:is_mzscheme 变量，可以使用 MzScheme 特定的内容。

此外，scheme.vim 也支持 Chicken Scheme->C compiler 的关键字。如果需要，定义
b:is_chicken 或 g:is_chicken。


SDL                                             *sdl.vim* *ft-sdl-syntax*

SDL 的高亮可能会缺少一些关键字，但 SDL 的关键字太多了，完全照顾过来是不太可能
的。

新的标准 SDL-2000 指定所有的标识符都是大小写敏感的 (以前并非如此)，而所有使用
的关键字必须或者是完全小写，或者完全大写。要使得高亮能够反映这些特性，你可以设
置如下的变量:
        :let sdl_2000=1

这也会设置很多新的关键字。如果你想屏蔽旧的关键字 (其实，这是个好主意)，可以
用:
        :let SDL_no_96=1

缩进可能还没完全处理好，不过我在自己的项目目前的应用里已经相当满意了。


SED                                             *sed.vim* *ft-sed-syntax*

要使得制表在普通的空白里突出显示 (方法是在制表上使用 Todo 高亮)，在 vimrc 文件
里如此定义 "highlight_sedtabs"

        :let highlight_sedtabs = 1

(这种特殊高亮只适用于搜索模式、替换文本、地址或者 Append/Change/Insert
命令里包含的文本中的制表。) 如果你打开该选项，那么最好把制表宽度设为一个字符；
这么做，你很容易计算字符串里的制表数量。

漏洞:

  transform 命令 (y) 和 substitute 命令的处理相同。也就是说，就语法文件而言，
  transform 和 substitute 接受相同的标志。这不正确 (Transform 不接受标志)。但
  我容忍这个问题，因为牵涉的命令需要很复杂的处理 (95 个模式，每个可能的模式定
  界符就需要一个模式)。


SGML                                            *sgml.vim* *ft-sgml-syntax*

SGML 文件里，标签的色彩方案工作方式如下。

开放标签的 <> 和关闭标签的 </> 的色彩不同。这是有意的。开放标签使用 'Function'
色彩，而关闭标签使用 'Type' 色彩 (见 syntax.vim 察看它们是怎么定义的)。

已知的标签名和 C 语句的色彩相同。未知的标签名和相应的 <> 或 </> 颜色相同，以便
纠错。

注意 这也适用于参数 (或属性) 的名字。已知的属性名和未知的标色不同。

一些 SGML 标签用于改变文本的显示。sgml.vim 语法色彩文件识别以下的标签，并相应
地改变普通文本的显示方式: <varname> <emphasis> <command> <function> <literal>
<replaceable> <ulink> 和 <link>。

如果你想改变文本显示的方式，必须重定义以下的语法组:

    - sgmlBold
    - sgmlBoldItalic
    - sgmlUnderline
    - sgmlItalic
    - sgmlLink 设定链接

要使得重定义能够工作，你必须重定义所有的组。在你的 vimrc (这是根据初始化时读入
文件的顺序) 里定义下面的变量
        :let sgml_my_rendering=1

在你的 vimrc 文件里加上这行，可以屏蔽这种显示方式:
        :let sgml_no_rendering=1

(从 Claudio Fleiner <claudio@fleiner.com> 的 html.vim 的帮助文本转来)


SH              *sh.vim* *ft-sh-syntax* *ft-bash-syntax* *ft-ksh-syntax*

这里讨论 "普通的" Unix 外壳，即 (Bourne) sh、bash 和 Korn shell。
(译者注: 原文作 Borne Shell。似为拼写错误，因为 Steve Bourne 是 sh 的作者)

Vim 试图根据文件名决定使用的 shell 类型:

    ksh : .kshrc* *.ksh
    bash: .bashrc* bashrc bash.bashrc .bash_profile* *.bash

如果这些都不符，那么就检查文件的第一行 (比如 /bin/sh  /bin/ksh  /bin/bash)。如
果第一行指定了外壳类型，那么就使用该类型。不过有的文件 (比如 .profile) 肯定是
外壳文件，但其类型并不容易推出。另外，有的系统里 sh 被符号链接到 "bash"
(linux、Windows+cygwin) 或 "ksh" (posix)。

你可以在 <.vimrc> 里设置下列三个变量中的一个，以指定全局的缺省值:

    ksh:
        let g:is_kornshell = 1
    posix: (和设置 is_kornshell 为 1 效果相同)
        let g:is_posix     = 1
    bash:
        let g:is_bash      = 1
    sh: (缺省) Bourne shell
        let g:is_sh        = 1

如果没有 "#! ..." 一行，而用户也没有用上述方法设定缺省的 sh.vim 语法设置，那么
syntax/sh.vim 假定使用 Bourne shell 语法。请不要在错误报告里引用 RFC 或者市场
占有率的统计数据 (译者注: 此处大概指希望使用其它缺省值的用户) -- 在 <.vimrc>
文件里自己选择系统使用的缺省 sh 版本就可以了。

如果你在 <.vimrc> 里设定
        let g:sh_fold_enabled= 1

那么若干语法项目 (Here 文档和函数体) 就可以进行语法折叠 (见 |:syn-fold|)。

如果你注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正的话，尝试设置
"sh_minlines" 内部变量为较大的值:
        :let sh_minlines = 500
这使得语法同步在第一个显示行之前的 500 行开始。缺省值为 200。使用较大的值的缺
点是重画会变慢。

如果你没有要同步的东西，但显示又很慢，可以设置 "sh_maxlines" 内部变量来加速。
比如:

        let sh_maxlines = 100

缺省值是 sh_minlines 的两倍。设置为较小的值可以提高显示的速度。缺点是高亮错误
出现的可能性也较大。


SPEEDUP (AspenTech plant simulator)             *spup.vim* *ft-spup-syntax*

Speedup 语法文件有如下选项:

- strict_subsections : 如果定义该变量，只有段 (section) 和子段 (subsection) 里
  的关键字会作为 Statement 高亮，而其它关键字不会 (比如 OPERATION 段里的
  WITHIN)。

- highlight_types : 该变量的定义使得流类型 (stream type)，比如 temperature 或
  pressure，用 Type 高亮，而不是普通的 Identifier。这里包括 DECLARE 段常见的类
  型；如果定义了自己的类型，要在语法文件里自己加入。

- oneline_comments : 该值可选 1 到 3，它决定了 # 风格的注释的高亮方式。

  oneline_comments = 1 : 允许偶数个 # 之后的正常 Speedup 代码。

  oneline_comments = 2 : 第二个 # 开始的代码显示为出错。这是缺省设置。

  oneline_comments = 3 : 如果某行包含超过一个 #，把整行显示为出错。

特别因为 OPERATION 段因为 PRESET (预设) 的变量而可能会很大，同步的正确设置很重
要。如果你的机器足够快，你可以在语法文件的末尾增加 minlines 和/或 maxlines 的
值。


SQL                                             *sql.vim* *ft-sql-syntax*
                                *sqlinformix.vim* *ft-sqlinformix-syntax*
                                *sqlanywhere.vim* *ft-sqlanywhere-syntax*

尽管有 ANSI 的 SQL 标准，多数数据库引擎都增加了自己的扩展。Vim 目前支持 Oracle
和 Informix 的 SQL 方言。Vim 缺省假设 "*.sql" 文件使用 Oracle SQL。

Vim 目前通过不同语法脚本提供不同供应商的 SQL 支持。你可以把 Vim 的缺省设置从
Oracle 改为任何目前支持的 SQL 类型。你也可以方便地为每个缓冲区设置不同的 SQL
方言.

详细的操作可见 |sql.txt|。


TCSH                                            *tcsh.vim* *ft-tcsh-syntax*

这里讨论名为 "tcsh" 的外壳。这是 csh 的超集。关于如何检测文件类型，见
|csh.vim|。

Tcsh 不允许字符串里的 \"，除非设置了 "backslash_quote" 外壳变量。如果你希望
VIM 认定不应该存在反斜杠 + 引号的构造，在 .vimrc 里加入这行:

        :let tcsh_backslash_quote = 0

如果你注意到往回滚动时，高亮出现问题，但 CTRL-L 重画又可以修正的话，尝试设置
"tcsh_minlines" 内部变量为较大的值:
        :let tcsh_minlines = 100
这使得语法同步在第一个显示行之前的 100 行开始。缺省值为 15。使用较大的值的缺点
是重画会变慢。


TEX                                             *tex.vim* *ft-tex-syntax*

*tex-folding*
要语法折叠么？

<syntax/tex.vim> 的版本 28 支持基于语法的 part、chapter、section、subsection
等等的折叠。把
        let g:tex_fold_enabled=1
放到你的 <.vimrc> 里，并 :set fdm=syntax。我建议把后者放到你的 LaTeX 文件末尾
的模式行里来执行:
        % vim: fdm=syntax

*tex-runon*
在注释还是数学模式里？

<syntax/tex.vim> 高亮支持 TeX、LaTeX 和部分的 AmsTeX。高亮支持包括三个主要的区
域: normal、texZone 和 texMathZone。尽管付出了相当的努力使得这些区域能正确地
终止，$..$ 和$$..$$ 定界的区域无法同步，因为开始和结束模式无法区别。因而，提供
了一个特殊的 "TeX 注释"
        %stopzone
它会使得 texZone 或 texMathZone 强迫终止。

*tex-slow*
语法高亮很慢？

如果你使用机器速度很慢，可能会想减小这些变量的值
        :syn sync maxlines=200
        :syn sync minlines=50
(特别是后者)。如果你的机器很快，可以考虑增大它们的值。它们主要影响同步 (确切地
说也就是: 如果有的话，哪个语法组包含屏幕顶部的文本？)。

*tex-error*
过多的 Error 高亮？

<tex.vim> 支持各种的词法检查。尽管错误检查经常很有用，它指示的地方实际上可能没
有错误。如果你有这个问题，可以在 <.vimrc> 里放上如下的语句:
        let tex_no_error=1
从而 <tex.vim> 提供的所有错误检查都会被抑制。

*tex-math*
需要新的数学模式的组？

如果你需要在 LaTeX 里包含新的数学组，下面的代码给出一个告诉你可以如何操作的例
子:
        call TexNewMathZone(sfx,mathzone,starform)
你需要为新数学组起一个独一无二的后缀 (目前，A-L 和 V-Z 被 <syntax/tex.vim> 自
己占用)。比如，看看 <syntax/tex.vm> 是怎么设置 eqnarray 的:
        call TexNewMathZone("D","eqnarray",1)
需要把 "mathzone" 换成新数学组的组名，然后在 .vim/after/syntax/tex.vim 里调
用。如果 "starform" 变量为真，意味着新数学组有星号的形式 (比如， eqnarray*)。

*tex-style*
开始新的风格？

你可以在 *.tex 文件里使用 "\makeatletter"，从而在命令里可用 "@"。不过，因为
*.tex 文件没有如下的后缀: sty cls clo dtx ltx，语法高亮会把这里使用的 @ 标为错
误。要解决这个问题:

        :let b:tex_stylish = 1
        :set ft=tex

把 "let g:tex_stylish=1" 放到你的 <.vimrc> 里，这会使得 <syntax/tex.vim> 总能
接受 @ 的这种使用方式。


TF                                              *tf.vim* *ft-tf-syntax*

tf 语法高亮有一个选项。

同步的 minlines 缺省为 100。如果你希望设为别的值，可以把 "tf_minlines" 设为你
希望的值。例如:

        :let tf_minlines = 你的选择


VIM                                             *vim.vim* *ft-vim-syntax*

准确的语法高亮和屏幕刷新速度需要一定的折衷。要提高准确性，你可能想增加
g:vim_minlines 变量的值。而 g:vim_maxlines 变量可以用来增加屏幕的刷新速度 (详
情可见 |:syn-sync|)。

        g:vim_minlines : 用于设置同步的 minlines
        g:vim_maxlines : 用于设置同步的 maxlines

g:vimembedscript 选项稍稍加快 vim 脚本的语法高亮载入，代价是外部脚本语言不支持
语法高亮 (目前有 perl、python、ruby 和 tcl)。

        g:vimembedscript == 1 (缺省)     <vim.vim> 打开支持的内嵌的脚本语言的
        g:vimembedscript 不存在          高亮: perl、python、ruby 和 tcl。

        g:vimembedscript == 0            不载入内嵌的脚本语言的语法高亮。

syntax/vim.vim 给出的错误高亮未必都正确；VimL 是一个要正确高亮难度很高的语言。
如果不想出现错误高亮，在你的 |vimrc| 里放上:

        let g:vimsyntax_noerror = 1


XF86CONFIG                              *xf86conf.vim* *ft-xf86conf-syntax*

XFree86 v3.x 和 v4.x 版本里，XF86Config 文件的语法有所不同。两者都支持且有自动
检测，但离完善还很远。你可能仍然需要手动指定版本。根据你的 XFree86 的版本，在
.vimrc 里把 xf86conf_xfree86_version 变量设为 3 或 4。例如:
        :let xf86conf_xfree86_version=3
如果混合使用多种版本，设置 b:xf86conf_xfree86_version 变量。

注意 不支持选项名的空格和下划线。如果你想高亮选项名，使用 "SyncOnGreen" 而不是
"__s yn con gr_e_e_n"。


XML                                             *xml.vim* *ft-xml-syntax*

缺省高亮 Xml 的命名空间。设置了下面的全局变量以后可以继承此设置:

        :let g:xml_namespace_transparent=1

                                                        *xml-folding*
xml 语法文件提供打开和关闭标签间的语法折叠 |folding| (见 |:syn-fold|)。这可以
用下面的代码打开

        :let g:xml_syntax_folding = 1
        :set foldmethod=syntax

注意: 语法折叠会显著地减慢语法高亮。大文件尤其如此。


X Pixmaps (XPM)                                 *xpm.vim* *ft-xpm-syntax*

xpm.vim 根据 XPM 文件的内容动态地建立语法项目。这样你就可以修改色彩规格字符
串。修改后，可用 ":set syn=xpm" 再次执行。

要复制带某颜色的像素，使用 "yl" 命令抽出 "像素" 然后在别的地方使用 "P" 插入。

你想用鼠标画图么？试试这些代码:
   :function! GetPixel()
   :   let c = getline(".")[col(".") - 1]
   :   echo c
   :   exe "noremap <LeftMouse> <LeftMouse>r".c
   :   exe "noremap <LeftDrag>  <LeftMouse>r".c
   :endfunction
   :noremap <RightMouse> <LeftMouse>:call GetPixel()<CR>
   :set guicursor=n:hor20          " 可以看到光标下的颜色
这使得右键变成像素提取工具，而左键成为一支笔。该代码只可用于每个像素一个字符的
XPM 文件，而且你不能在像素字符串之外点击。不过，你自己可以尝试改进之。

如果使用大小减半的字体，看其来会舒服得多。比如，在 X 上:
        :set guifont=-*-clean-medium-r-*-*-8-*-*-*-*-80-*

5. 定义语法                                             *:syn-define* *E410*

Vim 理解三种语法项目的类型:

1. 关键字
   它只能包含由 'iskeyword' 选项定义的关键字字符，而且不能包含其它语法项目。
   它必须匹配完整的单词 (在匹配的前后不能有其它的关键字字符)。
   关键词 "if" 只在 "if(a=b)" 里匹配，而不在 "ifdef x" 里匹配。因为 "(" 不是关
   键字字符，但 "d" 是。

2. 匹配
   它匹配单个正规表达式模式。

3. 区域
   它始于 "start" 正规表达式模式的匹配，结束于 "end" 正规表达式模式的匹配。两
者之间可以包含任何文本。其中，"skip" 正规表达式模式可以用来避免 "end" 模式的匹
配。

若干语法*项目*可以放在一个语法*组*里。你可以为一个语法组设置高亮属性。例如，你
可以定义 "/* .. */" 注释为一个项目，"// .." 注释为另一个，并把两者都放在
"Comment" 组里。这时，你就可以设置 "Comment" 以粗体字体和蓝色出现。你可以自由
选择各种组合，比如为每个语法项目设置一个高亮组，乃至把所有项目都放到一个组。这
取决于你如何指定你的高亮属性。把每个项目放到单独的组里的后果是你需要为很多组指
定高亮属性。

注意 语法组和高亮组类似。你为高亮组指定高亮属性，而这些属性会被用于同名的语法
组。

如果有多个项目在相同位置匹配，*最后*定义的那个胜出。这样，你可以覆盖较早定义的
匹配相同文本的语法项目。不过，关键字总是优先于匹配和区域，而匹配大小写的关键字
又优先于忽略大小写的关键字。


优 先 级                                                *:syn-priority*

如果多个语法项目可以匹配，使用如下规则:

1. 如果多个匹配或区域项目在相同的位置开始，最后定义者优先。
2. 关键字比匹配和区域项目优先。
3. 从较早位置开始的项目优先于从较后位置开始的项目。


定 义 大 小 写 敏 感                                    *:syn-case* *E390*

:sy[ntax] case [match | ignore]
        要求其后的 ":syntax" 命令在本设定为 "match" 时必须匹配大小写，本设定为
        "ignore" 时则可以忽略大小写。注意，它不影响之前的项目，而只影响其后直
        到下一个 ":syntax case" 命令为止的所有项目。


拼 写 检 查                                             *:syn-spell*

:sy[ntax] spell [toplevel | notoplevel | default]
        定义不在任何语法项目里的文本在何处进行拼写检查:

        toplevel:       文本进行拼写检查。
        notoplevel:     文本不进行拼写检查。
        default:        如果有 @Spell 簇，不进行拼写检查。

        语法项目里的文本用 @Spell 和 @NoSpell 簇 |spell-syntax|。如果没有
        @Spell 和 @NoSpell 簇，那么 "default" 和 "toplevel" 进行拼写检查。

        要激活拼写检查，必须置位 'spell' 选项。


定 义 关 键 字                                          *:syn-keyword*

:sy[ntax] keyword {group-name} [{options}] {keyword} .. [{options}]

        定义一系列关键字。

        {group-name}    是语法组名，比如 "Comment"。
        [{options}]     见下 |:syn-arguments|。
        {keyword} ..    是关键字列表，这些关键字成为该组的成员。

        示例:
  :syntax keyword   Type   int long char

        {options} 可以在该行的任何位置给出。它们应用于所有的关键字，包括选项之
        前的关键字。以下例子完全相同:
  :syntax keyword   Type   contained int long char
  :syntax keyword   Type   int long contained char
  :syntax keyword   Type   int long char contained
                                                                *E789*
        如果像 Vim 里的 Ex 命令那样，使用有可选尾部的关键字并把可选字符放在 []
        里，你可以一次定义各种变化形式:
  :syntax keyword   vimCommand   ab[breviate] n[ext]

        不要忘记只有所有字符都包含在 'iskeyword' 选项里才能作为关键字识别。如
        果有一个字符不是，该关键字永远不会被识别。不过，可以使用多字节字符，它
        们不需要出现在 'iskeyword' 里。

        关键字比匹配和区域有更高的优先级。如果有多个项目匹配，会优先使用关键
        字。关键字不会嵌套，也不能包含其它项目。

        注意 你不能使用和选项同名的关键字 (即使这里不允许的选项也不行)。这时，
        应该使用匹配。

        关键字的最大长度为 80 个字符。

        根据被包含与否的不同，可以多次定义同一关键字，例如，你可以定义一次不被
        包含的关键字并使用一个高亮组。而为被包含的同一关键字使用不同的高亮组。
        例如:
  :syn keyword vimCommand tag
  :syn keyword vimSetting contained tag
        如果发现独立于别的语法项目之外的 "tag"，使用 "vimCommand" 高亮组。如果
        发现 "tag" 出现在能包含 "vimSetting" 的项目里，则使用 "vimSetting"。


定 义 匹 配                                             *:syn-match*

:sy[ntax] match {group-name} [{options}] [excludenl] {pattern} [{options}]

        定义一个匹配。

        {group-name}            语法组名，比如 "Comment"。
        [{options}]             见下 |:syn-arguments|。
        [excludenl]             使得包含行尾匹配 "$" 的模式不扩展包含本项目的
                                匹配或者区域项目。必须在模式之前给出。
                                |:syn-excludenl|
        {pattern}               定义匹配的搜索模式。见下面的 |:syn-pattern|。
                                注意 模式可以匹配多于一行的模式，这使得匹配依
                                赖于 Vim 从哪里开始搜索模式。你需要确信同步机
                                制能正确处理这个问题。

        例如 (匹配字符常数):
  :syntax match Character /'.'/hs=s+1,he=e-1


定 义 区 域             *:syn-region* *:syn-start* *:syn-skip* *:syn-end*
                                                        *E398* *E399*
:sy[ntax] region {group-name} [{options}]
                [matchgroup={group-name}]
                [keepend]
                [extend]
                [excludenl]
                start={start_pattern} ..
                [skip={skip_pattern}]
                end={end_pattern} ..
                [{options}]

        定义一个区域。区域可以覆盖多行。

        {group-name}            语法组名，比如 "Comment"。
        [{options}]             见下 |:syn-arguments|。
        [matchgroup={group-name}]  其后定义的开始或者结束模式的匹配文本专用的
                                语法组。该语法组并不用于两者之间的文本。如果不
                                想开始或结束匹配使用另外的语法组，可以用 NONE
                                作为组名来复位。
                                见 |:syn-matchgroup|。
        keepend                 不允许被包含的匹配项目越过结束模式的匹配文本。
                                见 |:syn-keepend|。
        extend                  否决包含本区域的项目的 "keepend" 设置。见
                                |:syn-extend|。
        excludenl               使得包含行尾匹配 "$" 的模式不扩展包含本项目的
                                匹配或者区域。只适用于结束模式。必须在该模式之
                                前给出。|:syn-excludenl|
        start={start_pattern}   定义区域开始的搜索模式。见下 |:syn-pattern|。
        skip={skip_pattern}     定义不需要查找结束模式的区域内部文本的搜索模
                                式。见下 |:syn-pattern|。
        end={end_pattern}       定义区域结束的搜索模式。见下 |:syn-pattern|。

        示例:
  :syntax region String   start=+"+  skip=+\\"+  end=+"+

        开始 / 跳过 / 结束模式和其它选项可用任何顺序给出。跳过模式可有零到一
        个。开始和结束模式必须有一个或更多。这意味着，你可以忽略跳过模式，但你
        必须给出至少一个的开始和结束模式。在等号前后，可以使用空白字符 (不过多
        数情况下，其实没有空白字符更清楚一些)。

        如果给出多于一个的开始模式，只须匹配其中任何一个。这意味着这些开始模式
        之间是*或*的关系。如有多个匹配，使用最后一个。结束模式也是如此。

        结束模式从开始模式之后立即开始搜索，这里不考虑位移。这意味着，结束模式
        的匹配文本永远不会与开始模式的重叠。

        跳过和结束模式可以跨行匹配，但因为模式的搜索可以从任何一行开始，这经常
        不能如你所愿。跳过模式也不能避免下一行中结束模式的匹配。要避免麻烦，最
        好使用单行的模式。

        注意: 一个区域的开始完全取决于开始模式的匹配。不检查是否存在结束模式的
        匹配。下面_不能_工作:
                :syn region First  start="("  end=":"
                :syn region Second start="("  end=";"
        Second 总是在 First 之前得到匹配 (最后定义的模式享有更高的优先权)。
        Second 区域会继续到后面出现的 ';' 为止。这之前是否出现 ':' 无关紧要。
        要解决这个问题，可以使用匹配:
                :syn match First  "(\_.\{-}:"
                :syn match Second "(\_.\{-};"
        该模式使用 "\_." 匹配任何字符或换行符，并以 "\{-}" 重复 (重复尽量少的
        次数)。

                                                        *:syn-keepend*
        缺省，被包含的项目可以隐藏结束模式的匹配。这对嵌套有用。比如， "{" 开
        始 "}" 结束的区域可以包含另一个这样的区域。第一个遇到的 "}" 会结束被包
        含的区域，不是外面的那个:
            {           开始外层 "{}" 区域
                {       开始被包含的 "{}" 区域
                }       结束被包含的 "{}" 区域
            }           结束外层 "{} 区域
        如果你不希望如此，"keepend" 参数可以使得外层区域结束模式的匹配同时结束
        任何包含在内的项目。这使得相同区域的嵌套不再可能，但可以允许被包含项目
        高亮结束模式的部分内容，而不会因此跳过结束模式的匹配。例如:
  :syn match  vimComment +"[^"]\+$+
  :syn region vimCommand start="set" end="$" contains=vimComment keepend
        "keepend" 使得 vimCommand 总是在行尾结束，即使被包含的 vimComment 包括
        了 <EOL> 的匹配也不例外。

        如果不使用 "keepend"，在每个被包含项目的匹配文本之后，才会重新尝试结束
        模式的匹配。如果使用 "keepend"，寻找结束模式第一次出现的匹配，并截断任
        何被包含的项目。
                                                        *:syn-extend*
        "keepend" 的行为可以被 "extend" 参数改变。当一个项目使用 "extend" 的时
        候，包含它的外层项目所用的 "keepend" 被忽略，从而使得那个项目可以得到
        扩展。
        这可以使一些被包含的项目能扩展某区域，而另一些则不能。例如:

   :syn region htmlRef start=+<a>+ end=+</a>+ keepend contains=htmlItem,htmlScript
   :syn match htmlItem +<[^>]*>+ contained
   :syn region htmlScript start=+<script+ end=+</script[^>]*>+ contained extend

        这里，htmlItem 项目不扩展 htmlRef 项目，它只是用来高亮 <> 条目。而
        htmlScript 项目则扩展 htmlRef 项目。

        另一个例子:
   :syn region xmlFold start="<a>" end="</a>" fold transparent keepend extend
        定义使用 "keepend" 的区域，使得它的结尾不会被包含在内的项目所改变，比
        如匹配 "</a>" 以赋予不同高亮属性的那些项目。但如果 xmlFold 区域本身嵌
        套 (自己包含自己)，则应用 "extend"，使得嵌套在内的 "</a>" 只会结束里面
        的区域，而不是包含该区域的外层区域。

                                                        *:syn-excludenl*
        当一个匹配项目的模式或者区域项目的结束模式包含 '$' 以匹配行尾的时候，
        包含该项目的外部区域项目会在下一行继续。比如，使用 "\\$" (行尾出现的反
        斜杠) 的匹配项目可以使得一个通常在行尾结束的区域继续下去。这是缺省的行
        为。如果你不希望如此，有两个解决方法:
        1. 外部项目使用 "keepend"。这会使得所有被包含的项目不能扩展外部的匹配
           或区域项目。这可用于所有被包含的项目都不能扩展外部项目的场合。
        2. 在被包含的项目中使用 "excludenl"。这使得该匹配不能扩展外部的匹配或
           区域项目。这可用于只有一些被包含的项目不需要扩展外部项目的场合。
           "excludenl" 必须在它适用的模式之前给出。

                                                        *:syn-matchgroup*
        "matchgroup" 可以用来高亮开始和/或结束模式，使之和区域本体不同。例如:
  :syntax region String matchgroup=Quote start=+"+  skip=+\\"+  end=+"+
        会使得引号本身使用 "Quote" 组高亮。而其中的文本使用 "String" 高亮组。
        "matchgroup" 用于其后所有的开始和结束模式，直到下一个 "matchgroup" 为
        止。使用 "matchgroup=NONE" 回到不使用 matchgroup 的情况。

        用 "matchgroup" 高亮的开始或结束模式的匹配文本不会用于包含在该区域内的
        项目。这样可以避免被包含项目也能在开始或结束模式的匹配文本中匹配。
        "transparent" 选项不适用于使用 "matchgroup" 高亮的开始或结束模式的匹配
        文本。

        这里是一个例子，它以不同的颜色高亮三层括号:
   :sy region par1 matchgroup=par1 start=/(/ end=/)/ contains=par2
   :sy region par2 matchgroup=par2 start=/(/ end=/)/ contains=par3 contained
   :sy region par3 matchgroup=par3 start=/(/ end=/)/ contains=par1 contained
   :hi par1 ctermfg=red guifg=red
   :hi par2 ctermfg=blue guifg=blue
   :hi par3 ctermfg=darkgreen guifg=darkgreen

6. :syntax 参数                                         *:syn-arguments*

定义语法项目的 :syntax 命令接受多个参数。其中，通用的部分在这里解释。这些参数
可以用任何顺序给出，也可和模式相互间杂。

不是所有的命令都接受每个参数。下表显示什么参数不能在所有命令里使用:
                                                        *E395* *E396*
                    contains  oneline   fold  display  extend 
:syntax keyword          -       -       -       -       -
:syntax match           是       -      是      是      是
:syntax region          是      是      是      是      是

以下参数可以在所有三个命令里使用:
        contained
        containedin
        nextgroup
        transparent
        skipwhite
        skipnl
        skipempty


contained                                               *:syn-contained*

如果给出 "contained" 参数，本项目在顶层不会被识别。只有包含在另外一个项目里才
可以，而且那个项目必须给出 "contains" 参数且其中包含本项目。例如:
   :syntax keyword Todo    TODO    contained
   :syntax match   Comment "//.*"  contains=Todo


display                                                 *:syn-display*

如果给出 "display" 参数，本项目会在检测到高亮不会显示的时候被跳过。这样，高亮
速度可以加快，因为只要发现要显示的文本的语法状态就可以跳过本项目。

通常，你使用 "display" 来匹配满足以下条件的匹配和区域项目:
- 该项目不会跨过行尾。C 的例子: 包含 "/*" 的注释不能使用 "display"，因为它会在
  下一行继续。
- 该项目不包含会跨过行尾或使得本项目在下一行继续的项目。
- 该项目不改变任何包含它在内的项目的大小。C 的例子: 预处理指令里的匹配 "\\$"
  不能使用 "display"，因为它可以使得预处理指令的匹配变短。
- 该项目不允许其它项目匹配本来不能匹配的内容，而所扩展的匹配文本会走的太远。C
  的例子: 定义 "//" 注释的匹配不能使用 "display"，因为在该注释里的 "/*" 这时会
  匹配并开始一个跨越行尾的注释。

例如，在 C 程序里，"display" 可以用在:
- 数值的匹配
- 标签的匹配


transparent                                             *:syn-transparent*

如果给出 "transparent" (透明) 参数，本项目自身不会被高亮，但会使用包含它的外层
项目的高亮属性。这对本身不需要特殊高亮但要用来跳过一段文本的语法项目有用。

除非包含 transparent 的这个项目本身包含了 "contains" 参数，"contains="
参数会从外层的项目继承，要避免包含不需要的项目，可使用 "contains=NONE"。例如，
高亮字符串里的单词，但不包括 "vim":
        :syn match myString /'[^']*'/ contains=myWord,myVim
        :syn match myWord   /\<[a-z]*\>/ contained
        :syn match myVim    /\<vim\>/ transparent contained contains=NONE
        :hi link myString String
        :hi link myWord   Comment
"myVim" 匹配出现在 "myWord" 之后，因而它是更优先的匹配 (在相同的位置上，后出
现的匹配优先于先出现的匹配)。"transparent" 参数使得 "myVim" 的匹配使用和
"myString" 相同的高亮，但它本身不再包含其它项目。如果没有指定 "contains=NONE"
参数，那么 "myVim" 会使用 myString 的 contains 参数，从而包含了 "myWord"，因而
被高亮为 Constant (译者注: 应为 Comment)。这之所以会发生，是因为被包含的项目不
会在同样的位置上匹配外层同一个语法项目，所以这里，在最内层的 "myVim" 匹配不能
否决 "myWord" 的匹配。

如果你看有色彩的文本，它实际上是由一层层被包含的项目组成的。被包含的项目在包含
它的项目之上，因而你能看到被包含的项目。如果一个被包含的项目是透明的，你会看透
它，从而看到包含它的项目。以图示之:

                从这里看

            |   |   |   |   |   |
            V   V   V   V   V   V

               xxxx       yyy           被包含更深的项目
            ....................        被包含项目 (透明)
        =============================   第一个项目

'x'、'y' 和 '=' 分别表示一种高亮的语法项目。'.' 代表透明层。

你实际看到的是:

        =======xxxx=======yyy========

这里，你 "看穿" 了透明的 "....".


oneline                                                 *:syn-oneline*

"oneline" 参数指示本区域不会跨过行边界。它必须在当前行内完整匹配。不过，如果本
区域包含跨行的项目，那么本区域还是会从下一行继续。被包含的项目可以用来识别继续
行的模式。不过，结束模式必须仍然在第一行上匹配，不然本区域根本不会开始。

如果开始模式包含 "\n" 从而匹配换行符，结束模式必须在开始模式结束处所在的同一行
上找到。该结束模式也可以包含换行符。因而，"oneline" 参数只是意味着开始模式的结
束处和结束模式的开始处必须在同一行上。这一点，即使跳过模式包含换行符也不能改
变。


fold                                                    *:syn-fold*

"fold" 参数使得本项目的折叠级别加 1。示例:
   :syn region myFold start="{" end="}" transparent fold
   :syn sync fromstart
   :set foldmethod=syntax
这使得每个 {} 块形成一个折叠。

该折叠从项目开始的行开始，而在项目结束之行上结束。如果开始和结束处在同一行，则
不形成折叠。'foldnestmax' 选项限制语法折叠的嵌套级别。
{only 只有在 Vim 编译时带 |+folding| 特性才有效}


                        *:syn-contains* *E405* *E406* *E407* *E408* *E409*
contains={groupname}...

"contains" 参数跟随语法组名的列表。这些组因而被允许包含在本项目里 (它们可能扩
展包含它们的组的结束位置)。这使得匹配和区域的递归嵌套成为可能。如果没有
"contains" 参数，本项目不能包含任何组。组名不需要在这里的使用前定义。

contains=ALL
                如果唯一在包含列表里出现的名字是 "ALL"，那么本项目里可以包含所
                有的组。

contains=ALLBUT,{group-name}...
                如果包含列表的第一个名字是 "ALLBUT"，那么除了列出的那些以外，
                所有的组都可以出现在本项目里。例如:
  :syntax region Block start="{" end="}" ... contains=ALLBUT,Function

contains=TOP
                如果包含列表的第一个名字是 "TOP"，那么所有不包含 "contained"
                参数的组都可以接受。
contains=TOP，{group-name},..
                类似于 "TOP"，但除了列出的组以外。

contains=CONTAINED
                如果包含列表的第一个名字是 "CONTAINED"，那么所有包含
                "contained" 参数的组都可以接受。
contains=CONTAINED，{group-name},..
                类似于 "CONTAINED"，但列出的组除外。


"contains" 列表里的 {group-name} 可以是模式。所有匹配该模式的组名都会包含进来
(或者排除出去，如果使用 "ALLBUT" 的话)。该模式不能包含空白或者 ','。例如:
   ... contains=Comment.*,Keyw[0-3]
在执行 syntax 命令时完成该匹配。后来定义的组不会再参与匹配。另外，如果本
syntax 命令自己定义一个新组，它也不会参与匹配。小心: 在文件里放入 syntax 命令
的时候，你不能指望某些组_没有_定义，因为该文件以前可能已经执行过。而
":syn clear" 并不会删除组名。

被包含的组也会匹配一个区域项目的开始和结束模式。如果不想如此，可以用
"matchgroup" 参数 |:syn-matchgroup|。"ms=" 和 "me=" 位移可以用来调整被包含项
目能够匹配的区域。注意 这同时可能限制了高亮的区域。


containedin={groupname}...                              *:syn-containedin*

"containedin" 参数跟随语法组名的列表。然后，本项目就可以包含在那些组里，就像那
些项目使用了包含本项目的 "contains=" 参数一样。

{groupname}... 的使用方式和 "contains" 相同，见上面的解释。

这可以用于后加的语法项目。一个项目可以告知要包含在已经存在的项目里面，而无须修
改后者的定义。例如，要在载入 C 语法以后高亮 C 注释里的一个单词:
        :syn keyword myword HELP containedin=cComment contained 
注意 同时使用了 "contained" 参数是为了避免本项目在顶层得到匹配。

"containedin" 的匹配被加到该项目可以出现的其它地方。像平常一样，本项目也可以使
用 "contains" 参数。不要忘记关键字项目不可能包含其它项目。所以把它们加在
"containedin" 里是徒劳的。


nextgroup={groupname}...                                *:syn-nextgroup*

"nextgroup" (下一个组) 参数跟随语法组名的列表，以逗号分隔 (和 "contains" 类
似，你也可以使用模式)。

如果给出 "nextgroup" 参数，提到的语法组会在本匹配或区域结束之后尝试匹配。如果
没有一个组能够匹配，高亮和平常一样继续。如果有匹配，则使用匹配的组高亮，即使该
组没有在当前组的 "contains" 字段里提到，就像这里的组给赋予了比其它的组更高的优
先级一样。例如:
   :syntax match  ccFoobar  "Foo.\{-}Bar"  contains=ccFoo
   :syntax match  ccFoo     "Foo"           contained nextgroup=ccFiller
   :syntax region ccFiller  start="."  matchgroup=ccBar  end="Bar"  contained

会分别高亮 "Foo" 和 "Bar"，但只有在 "Bar" 跟在 "Foo" 之后才行。在下面的文本行
里，"f" 显示使用 ccFoo 的高亮，而 "bbb" 则是使用 ccBar 的地方。

   Foo asdfasd Bar asdf Foo asdf Bar asdf
   fff         bbb      fff      bbb

注意 ".\{-}" 的使用跳过尽可能少的内容以到达下一个 Bar。如果使用了 ".*"，"Bar"
和 "Foo" 之间的 "asdf" 会以 "ccFoobar" 组高亮，因为 ccBar 匹配行内第一个 "Foo"
和最后一个 "Bar" 的全部内容 (见 |pattern|)。


skipwhite                                               *:syn-skipwhite*
skipnl                                                  *:syn-skipnl*
skipempty                                               *:syn-skipempty*

这些参数只能和 "nextgroup" 组合使用。它们可以用来指定如何跳过一些文本到达下一
个组:
        skipwhite       跳过空格和制表字符
        skipnl          跳过换行符
        skipempty       跳过空行 (意味着 "skipnl")

如果 "skipwhite" 存在，空白字符只有在没有下一个组会匹配空白时才会跳过。

如果 "skipnl" 存在，下一个组的匹配会在第二行内寻找。这只有在当前项目在行尾结束
时才会发生！如果 "skipnl" 不存在，下一个组只会在当前项目相同的行上寻找。

如果在寻找下一个组时跳过文本，其它组的匹配就会忽略。只有在没有下一个组匹配时，
其它的项目才会重新尝试被匹配。这意味着下一个组，包括跳过的空白和 <EOL>，的匹配
比其它项目的优先级要高。

示例:
  :syn match ifstart "\<if.*"   nextgroup=ifline skipwhite skipempty
  :syn match ifline  "[^ \t].*" nextgroup=ifline skipwhite skipempty contained
  :syn match ifline  "endif"    contained
注意 "[^ \t].*" 匹配所有的非空白文本。这样，它也能匹配 "endif"。所以 "endif"
匹配项目必须放在最后，以取得优先权。
注意 本例子不适用于嵌套的 "if"。你需要加上 "contains" 参数才行 (本例之所以省
略，是为了简洁起见)。

7. 语法模式                                     *:syn-pattern* *E401* *E402*

在 syntax 命令里，模式必须被两个相同的字符包围。这和 ":s" 命令类似。最常用的是
双引号。但如果模式本身包含双引号，你可以使用别的不在模式里出现的字符。例如:
  :syntax region Comment  start="/\*"  end="\*/"
  :syntax region String   start=+"+    end=+"+   skip=+\\"+

关于模式的解释，见 |pattern|。对语法模式的解释总是假设打开了 'magic' 选项，而
与实际的 'magic' 值无关。而且也假设 'cpoptions' 里没有 'l' 标志位。这些设置使
得语法文件易移植，而独立于 'compatible' 和 'magic' 的设置。

要避免能够匹配空字符串的模式，比如 "[a-z]*"。这会显著减慢高亮，因为这样的模式
会在任何地方得到匹配。

                                                *:syn-pattern-offset*
模式可以后跟一个字符位移。它可以用来修改高亮的部分，也可以修改匹配或区域项目的
文本区域 (只有其它项目的匹配会受影响)。两者都是相对于已经匹配的模式的。跳过模
式的字符位移可以用来指示从哪里开始继续寻找结束模式。

位移的形式是 "{what}={offset}"
{what} 可以是七种字符串之一:

ms      匹配开始        匹配文本开始的偏移
me      匹配结束        匹配文本结束的偏移
hs      高亮开始        高亮开始的偏移
he      高亮结束        高亮开始的偏移
rs      区域开始        区域本体开始的偏移
re      区域结束        区域本体结束的偏移
lc      引导上下文      超越模式的 "引导上下文" 的偏移

{offset} 可以是:

s       模式匹配部分的开始位置
s+{nr}  模式匹配部分的开始位置向右 {nr} 个字符
s-{nr}  模式匹配部分的开始位置向左 {nr} 个字符
e       模式匹配部分的结束位置
e+{nr}  模式匹配部分的结束位置向右 {nr} 个字符
e-{nr}  模式匹配部分的结束位置向左 {nr} 个字符
{nr}    (只用于 "lc"): 向左 {nr} 个字符开始匹配

例如: "ms=s+1"，"hs=e-2"，"lc=3"。

尽管所有的位移形式在任何模式之后都能接受，它们不都有意义。下表说明什么样的位移
在实际中会应用到:

                    ms   me   hs   he   rs   re   lc 
匹配项目            是   是   是   是   -    -    是
区域项目开始模式    是   -    是   -    是   -    是
区域项目跳过模式    -    是   -    -    -    -    是
区域项目结束模式    -    是   -    是   -    是   是

位移可用 ',' 连接。例如:
  :syn match String  /"[^"]*"/hs=s+1,he=e-1

    一些 "字符串" 文本
          ^^^^^^                高亮部分

注意:
- 模式和位移字符之间不能有空白。
- 高亮区域永远不会超出匹配文本的范围。
- 结束模式上的负偏移不一定总能用，因为结束模式可能在高亮本应结束的地方才检测
  到。
- 匹配不能从实际匹配的模式所在的行之外开始。这样不行: "a\nb"ms=e。高亮可以从另
  一个行开始，这样没有问题: "a\nb"hs=e。

示例 (匹配注释，但不高亮 /* 和 */):
  :syntax region Comment start="/\*"hs=e+1 end="\*/"he=s-1

        /* 这是一个注释 */
          ^^^^^^^^^^^^^^          高亮部分

一个更复杂的例子:
  :syn region Exa matchgroup=Foo start="foo"hs=s+2,rs=e+2 matchgroup=Bar end="bar"me=e-1,he=e-1,re=s-1

         abcfoostringbarabc
            mmmmmmmmmmm     匹配
              ssrrrreee     高亮 开始 (s)/区域 (r)/结束 (e)
                                ("Foo"、"Exa" 和 "Bar")

引导上下文                      *:syn-lc* *:syn-leading* *:syn-context*

注意: 这是一个已经废弃的特性，包含它只是为了和以前的 Vim 版本后向兼容。现在，
我们推荐使用在模式里使用 |/\@<=| 构造。

"lc" 位移指定引导上下文 -- 模式的一部分: 必须存在，但不包含在实际的匹配中。形
如 "lc=n" 的位移会使得 Vim 在试图匹配模式前先后退 n 列，从而可以使得已在较早的
模式中匹配的字符仍然可以做为本匹配的引导上下文。这可用于，比如说，要求本匹配不
出现在某个前导的 "转义" 字符之后:

  :syn match ZNoBackslash "[^\\]z"ms=s+1
  :syn match WNoBackslash "[^\\]w"lc=1
  :syn match Underline "_\+"

          ___zzzz ___wwww
          ^^^     ^^^     匹配 Underline
              ^ ^         匹配 ZNoBackslash
                     ^^^^ 匹配 WNoBackslash

"ms" 位移自动设为与 "lc" 位移相同的值，除非你显式地设置 "ms"。


多行模式                                                *:syn-multi-line*

模式里可以包含 "\n" 匹配换行符。多数情况下，它能正常工作，但有以下一些例外。

使用带位移的开始模式时，匹配不允许从真实匹配之后的行开始。不过，高亮不存在这样
的问题。

跳过模式可以包含 "\n"，但结束模式的搜索会从下一行的第一个字符开始，即使跳过模
式匹配该字符也是如此。这是因为重画可以从区域中间的任何一行启动，而不会检查跳过
模式是否从那一行之前就已经开始的缘故。例如，如果跳过模式是 "a\nb" 而结束模式为
"b"，结束模式的确会匹配下面情况的第二行:
         x x a
         b x x
通常，这意味着跳过模式不应匹配 "\n" 之后的任何字符。


外部匹配                                                *:syn-ext-match*

以下附加的正规表达式项目可以用在区域项目的模式中:

                                                */\z(* */\z(\)* *E50* *E52*
    \z(\)       标记该子表达式为 "外部的"，这意味着它可以在别的模式匹配里访
                问。目前，只能在语法区域的开始模式中应用。

                                        */\z1* */\z2* */\z3* */\z4* */\z5*
    \z1  ...  \z9                       */\z6* */\z7* */\z8* */\z9* *E66* *E67*
                匹配和前面的开始模式匹配里相应子表达式的匹配的相同的字符串。

有时区域项目的开始和结束模式需要共享一个相同的子表达式。常见的例子是 Perl 和许
多 Unix 外壳里的 "here" 文档。这种效果可以通过特殊的 "\z" 正规表达式项目完成。
它把子表达式标为 "外部的"，也就是说可以从定义所在的模式的外部引用。例如，here
文档的例子可以如此完成:
  :syn region hereDoc start="<<\z(\I\i*\)" end="^\z1$"

由此可见，\z 实际上有双重任务。在开始模式里，它标记 "\(\I\i*\)" 子表达式为外部
的；在结束模式里，它把 \1 反向引用重新定义为指向开始模式里的第一个外部子表达式
的外部引用。跳过模式里也可以使用外部引用:
  :syn region foo start="start \(\I\i*\)" skip="not end \z1" end="end \z1"

注意 普通和外部子表达式是完全不相关联，它们分别索引。如果模式 "\z(..\)\(..\)"
应用于字符串 "aabb"，\1 会指向 "bb" 而 \z1 会指向 "aa"。也要 注意，外部子表达
式不能和普通的子表达式那样，在同一个模式里作为反向引用来访问。如果你需要把一个
子表达式同时作为普通和外部子表达式来使用，可以嵌套使用这两者，形如
"\(\z(...\)\)"。

注意 这里只能使用行内的匹配，不能从外部引用多行匹配。

8. 语法簇                                               *:syn-cluster* *E400*

:sy[ntax] cluster {cluster-name} [contains={group-name}..]
                                 [add={group-name}..]
                                 [remove={group-name}..]

本命令允许你把若干语法组捆绑在一起，以便使用单个名字访问。

        contains={group-name}..
                本簇使用此处指定的组名列表。
        add={group-name}..
                将指定的组加入本簇。
        remove={group-name}..
                将指定的组从本簇里删除。

用这种方式定义的簇可以在 contains=..、nextgroup=..、add=.. 或者 remove=.. 的列
表里使用，只要加上 "@" 前缀即可。用这种表示方式，你可以隐含地在指定一个簇的内
容之前先声明之。

示例:
   :syntax match Thing "# [^#]\+ #" contains=@ThingMembers
   :syntax cluster ThingMembers contains=ThingMember1,ThingMember2

如同前例所暗示的，对簇的修改追溯既往；可以说，在最后一刻才进行簇成员身份的检
查:
   :syntax keyword A aaa
   :syntax keyword B bbb
   :syntax cluster AandB contains=A
   :syntax match Stuff "( aaa bbb )" contains=@AandB
   :syntax cluster AandB add=B    " 现在两个关键字都在 Stuff 里匹配

对嵌套的簇而言，这也有若干意含:
   :syntax keyword A aaa
   :syntax keyword B bbb
   :syntax cluster SmallGroup contains=B
   :syntax cluster BigGroup contains=A,@SmallGroup
   :syntax match Stuff "( aaa bbb )" contains=@BigGroup
   :syntax cluster BigGroup remove=B    " 没有效果，因为 B 不在 BigGroup 里
   :syntax cluster SmallGroup remove=B  " 现在 Stuff 不再匹配 bbb

9. 包含语法文件                                         *:syn-include* *E397*

一个语言的语法文件经常需要包含相关语言的语法文件。取决于它们实际的关系，可以用
两种不同的方式完成:

        - 如果允许被包含的语法文件里的顶层的语法项目也出现在包含它的语法的顶层
          中，可以简单的使用 |:runtime| 命令:

  " 在 cpp.vim 里:
  :runtime! syntax/c.vim
  :unlet b:current_syntax

        - 如果被包含的语法文件里的顶层语法项目应在包含它的语法的某区域中应用，
          可以使用 ":syntax include" 命令:

:sy[ntax] include [@{grouplist-name}] {file-name}

          被包含文件里定义所有的语法项目会自动加上 "contained" 标志。同时，如
          果指定了组群 (簇)，被包含文件所有的顶层语法项目会加到该组群里。

   " 在 perl.vim 里:
   :syntax include @Pod <sfile>:p:h/pod.vim
   :syntax region perlPOD start="^=head" end="^=cut" contains=@Pod

          如果 {file-name} 是绝对路径 (以 "/"、"c:"、"$VAR" 或者 "<sfile>" 开
          始)，则载入该文件。如果它是是相对路径 (例如，"syntax/pod.vim")，则先
          在 'runtimepath' 里搜索该文件，然后载入所有匹配的文件。建议使用相对
          路径，因为它允许用户用自己的版本替代被包含的文件，而不用修改使用
          ":syn include" 命令的文件。

10. 同步                                        *:syn-sync* *E403* *E404*

Vim 期待在文档的任何位置都能开始重画过程。为此目的，它需要知道重画开始所在的位
置相应的语法状态。

:sy[ntax] sync [ccomment [group-name] | minlines={N} | ...]

有四个同步方法:
1. 总是从文件头开始分析。
   |:syn-sync-first|
2. 基于 C 风格的注释。Vim 理解 C 注释的工作方式，因而可以发现当前行是在注释里
   面还是外面。
   |:syn-sync-second|
3. 回跳若干行，从那里开始分析。
   |:syn-sync-third|
4. 反向搜索某模式的匹配文本，从那里开始同步。
   |:syn-sync-fourth|

                                *:syn-sync-maxlines* *:syn-sync-minlines*
对于后三个方法而言，开始分析所在的行范围受到 "minlines" 和 "maxlines" 的限制。

如果给出 "minlines={N}" 参数，分析总是至少倒退给出的行数，然后才开始。这适用于
分析过程在能判断正确之前至少需要若干行的情况、或者完全无法使用同步机制的场合。

如果给出 "maxlines={N}" 参数，反向搜索注释或者同步用搜索模式的行数限于 N 行之
内 (包括 "minlines" 指定的行数)。可用于同步的项目较少且机器较慢的场合。例如:

   :syntax sync ccomment maxlines=500

                                                *:syn-sync-linebreaks*
使用可以匹配多行的模式时，某行的改变可以使得匹配不再能从上一行开始匹配。这意味
着同步必须从改变发生所在位置之前就进行。具体需要多少行可由 "linebreaks" 参数指
定。例如，如果模式包含一个换行符，可以这样:
   :syntax sync linebreaks=1
结果是，重画至少从改变所在之前的一行开始。缺省的 "linebreaks" 值为零。通常，
"minlines" 的值比 "linebreaks" 要大。


第一种同步方法:                         *:syn-sync-first*

   :syntax sync fromstart

文件从头开始分析。这使得语法高亮完全准确，但对很长的文件需时也久。Vim 预存以前
分析过的文本，所以只有第一次分析文本的时候才会缓慢。不过，如果修改了文本，其后
的部分需要重新分析 (最差情况下: 一直到文件尾)。

使用 "fromstart" 等价于把 "minlines" 指定为很大的数字。


第二种同步方法:                         *:syn-sync-second* *:syn-sync-ccomment*

第二种方法只需指定 "ccomment" 参数。示例:
   :syntax sync ccomment

Vim 如果发现显示开始的行出现在 C 风格注释的内部，就使用组名为 "Comment" 的最后
一个区域语法项目。这需要组名为 "Comment" 的区域项目存在！也可指定替代的组名，
例如:
   :syntax sync ccomment javaComment
这意味着最后出现的 "syn region javaComment" 会用来检测 C 注释的区域。只有该区
域确实包含了开始模式 "\/*" 和结束模式 "*\/" 的时候才能有效。

"maxlines" 参数可以用来限制搜索的行数。"minlines" 参数用来指定至少回退若干行才
开始 (例如一些只占用若干行，但很难同步的构造).

注意: 如果使用跨行且包含 "*/" 的字符串，C 注释的同步方法不一定能正确工作。让字
符串跨行是一个不好的编程习惯 (许多编译器会给出警告)，而 "*/" 出现在注释 (译者
注: 应为字符串) 的机率又相当小，一般很难注意到这个限制。


第三种同步方法:                         *:syn-sync-third*

第三种同步方法只要指定 "minlines={N}" 参数。Vim 会从行号上减去 {N} 然后从那里
开始分析。这意味着需要额外分析 {N} 行，该方法也因此较慢。例如:
   :syntax sync minlines=50

"lines" 等价于 "minlines" (用于较老的版本)。


第四种同步方法:                         *:syn-sync-fourth*

本方法试图在若干指定区域的一端同步，称为同步模式。因为只有区域可以跨行。所以如
果我们能找到某区域的一端，或许就可以知道现在在哪个语法项目之中。该方法中，搜索
从重画开始所在的上一行开始，然后在文件中反向进行。

和非同步的语法项目类似，同步项目也可以使用 contained、matches、nextgroup 等。
但有如下区别:
- 不能使用关键字项目。
- 使用 "sync" 关键字的语法项目构成完全独立的语法项目组。你不能混合同步组和非同
  步组。
- 匹配在缓冲区里 (逐行) 反向进行，而不是正向。
- 可以给出行继续的模式，用于决定哪些行的组合可以在搜索时当成单行。这意味着搜索
  指定项目的匹配从包含行继续模式的连续多行的第一行开始。
- "nextgroup" 或 "contains" 只适用于一行 (或者连续行构成的组合) 之内。
- 使用区域项目时，必须在同一行上 (或者连续行构成的组合) 开始和结束。否则，假定
  行尾 (或者连续行构成的组合的尾部) 会结束此项目。
- 如果找到同步模式的匹配，该行 (或者连续行构成的组合) 的其余部分会搜索其它匹
  配。最后发现的匹配被使用。这可以用于同时包括区域开始和结束的行 (例如，C 注释
  /* this */，使用最后找到的 "*/")。

有两个使用同步模式的匹配方法:
1. 高亮分析从重画开始处开始 (也就是同步模式的搜索起点)。必须指定在那里出现的合
   法语法组。如果跨行的区域不会包含别的区域时，这很有效。
2. 高亮分析从匹配之后立即开始。必须指定匹配之后立即出现的合法语法组。可
   用于上述方法不适用的情形。它慢得多，因为需要分析更多的文本。
可以同时使用两种类型的同步模式。

除了同步模式以外，还可以指定另外的匹配和区域项目，以跳过不需要的匹配。

[之所以单独给出同步模式，是因为多数情况下，同步点的搜索比高亮部分的确定要简单
得多。而模式的减少意味着速度的 (大大) 加快。]

                                            *syn-sync-grouphere* *E393* *E394*
    :syntax sync match {sync-group-name} grouphere {group-name} "pattern" ..

        "这里的组"，定义用于同步的匹配。{group-name} 为匹配之后立刻出现的语法
        组名 (译者注: 但不一定从那里开始，尤其是同步模式本身就可以属于该组)。
        文本的高亮分析在匹配之后立刻进行。{group-name} 至少应包含一个区域项
        目，并使用其中的第一个这样的定义。"NONE" 用来指示匹配之后不存在语法
        组。

                                                *syn-sync-groupthere*
    :syntax sync match {sync-group-name} groupthere {group-name} "pattern" ..

        "那里的组"，类似于 "grouphere"，但 {group-name} 是在同步点的搜索起点所
        在行的行首使用的语法组名。匹配和同步点的搜索起点之间的文本假定不会改变
        语法的高亮。例如，在 C 里，你可以反向搜索 "/*" 和 "*/"。如果先找到
        "/*"，你知道在注释内部，所以 "那里的组" 是 "cComment"。如果先找到 "*/"
        ，你知道不在注释里，所以 "那里的组" 是 "NONE"。(实际应用中更复杂，因为
        "/*" 和 "*/" 可以出现在字符串中。留给读者作为练习吧……).

    :syntax sync match ..
    :syntax sync region ..

        没有 "groupthere" 参数。定义区域或匹配项目，在同步点搜索过程中跳过这些
        项目 (译者注: 注意 同步模式只能使用匹配项目，但在这里定义的同步过程的
        "跳过" 模式可以指定区域或匹配项目。区域项目的限制上面已有叙述)。

                                                *syn-sync-linecont*
    :syntax sync linecont {pattern}

        如果 {pattern} 在行内匹配，本行被认为会在下一行继续。这意味着同步点的
        搜索会把这些行当作连接在一起的一行处理。

如果同时给出 "maxlines={N}" 参数，寻找匹配的搜索行数限于 N 行之内。可以用于同
步项目很少且机器速度较慢的场合。例如:
   :syntax sync maxlines=100

你可以这样清除所有的同步设置:
   :syntax sync clear

你也可以清除特定的同步模式:
   :syntax sync clear {sync-group-name} ..

11. 列出语法项目                        *:syntax* *:sy* *:syn* *:syn-list*

本命令列出所有的语法项目:

    :sy[ntax] [list]

要显示单个语法组的所有语法项目:

    :sy[ntax] list {group-name}

要列出单个簇的所有语法组:                                       *E392*

    :sy[ntax] list @{cluster-name}

":syntax" 命令的其它参数见上。

注意 ":syntax" 命令可以简化成 ":sy"，不过 ":syn" 更常用，因为看起来更舒服点。

12. Highlight 命令                      *:highlight* *:hi* *E28* *E411* *E415*

有三种类型的高亮组:
- 用于特定语言的。这些组的名字以该语言的名字开始。它们中很多没有属性，而是链接
  到第二种类型的组。
- 用于所有语法语言的。
- 用于 'highlight' 选项的。
                                                        *hitest.vim*
用这个命令，你可以看到当前激活的所有组:
    :so $VIMRUNTIME/syntax/hitest.vim
它会打开一个新窗口，其中包含所有的高亮组名，以它们本身的颜色显示。

                                                *:colo* *:colorscheme* *E185*
:colo[rscheme] {name}   载入色彩方案 {name}。它会在 'runtimepath' 里搜索
                        "colors/{name}.vim"，载入第一个找到的文件。
                        要看到当前激活的色彩方案的名字 (如果有的话):
                                :echo g:colors_name
                        它不能递归调用，所以你不能在色彩方案脚本里使用
                        ":colorscheme"。
                        色彩方案载入后，激活 |ColorScheme| 自动命令事件。关于
                        如何编写色彩方案文件的信息:
                                :edit $VIMRUNTIME/colors/README.txt

:hi[ghlight]            列出当前所有的有属性设置的高亮组。

:hi[ghlight] {group-name}
                        列出一个高亮组。

:hi[ghlight] clear      复位高亮设置为缺省值。删除所有用户增加的组的高亮属性。
                        用当前的 'background' 的值来决定所使用的缺省颜色。

:hi[ghlight] clear {group-name}
:hi[ghlight] {group-name} NONE
                        屏蔽一个高亮组的所有高亮设置。并_不_复原缺省的颜色。

:hi[ghlight] [default] {group-name} {key}={arg} ..
                        增加高亮组，或者更改已有的组高亮设置。
                        |highlight-args| 说明 {key}={arg} 的参数。
                        |:highlight-default| 说明可选的 [default] 参数。

通常，在启动时加入高亮组。它设置高亮的缺省值。在这之后，你可以使用附加的
highlight 命令来修改你希望设置为非缺省值的参数。也可以用 "NONE" 来撤销某个值并
恢复缺省的值。

修改颜色的简单方式是 |:colorscheme| 命令。它载入一个文件，里面包含了这样的
":highlight" 命令:

   :hi Comment  gui=bold

注意 所有没有包含在内的设置都保持原样，只使用指定的字段，从而和以前的设置进行
了合并。所以实际结果就像用了下面这样的一条命令:
   :hi Comment  term=bold ctermfg=Cyan guifg=#80a0ff gui=bold

                                                        *:highlight-verbose*
如果列出高亮组时 'verbose' 非零，同时列出高亮组最近在哪里设置。例如:
        :verbose hi Comment
        Comment        xxx term=bold ctermfg=4 guifg=Blue 
           Last set from /home/mool/vim/vim7/runtime/syntax/syncolor.vim 

如果使用了 ":hi clear"，那么列出缺省值的同时提到使用该命令的脚本。详见
|:verbose-cmd|。

                                        *highlight-args* *E416* *E417* *E423*
用于高亮，有三种类型的终端:
term    普通的终端 (vt100、xterm)
cterm   色彩终端 (MS-DOS 控制台、color-xterm，带有 "Co" termcap 项目的终端)
gui     GUI

每种类型可以分别设置高亮属性。这样，单个语法文件就可用于所有的终端，并使用每个
终端最优的高亮设置。

1. 普通终端的高亮参数

                                        *bold* *underline* *undercurl*
                                        *inverse* *italic* *standout*
term={attr-list}                        *attr-list* *highlight-term* *E418*
        attr-list 是逗号分隔的下述项目 (不能有空格) 的列表 (任何顺序都可以):
                bold
                underline
                undercurl       不一定总是可用
                reverse
                inverse         等同于 reverse
                italic
                standout
                NONE            不使用属性 (用于复位)

        注意 这里使用 "bold" 和使用粗体字体都可以，效果相同。
        "undercurl" 是波浪状的下划线。如果不能用 "undercurl"，使用 "underline"
        代替。一般，只有 GUI 才能使用 "undercurl"。颜色可用 |highlight-guisp|
        设置。

start={term-list}                               *highlight-start* *E422*
stop={term-list}                                *term-list* *highlight-stop*
        可以得到终端上的非标准的属性的终端代码的列表。

        "start" 参数指定的转义码序列在高亮区域的字符之前被写入，它可以是你希望
        给终端发送的用于高亮区域的任何内容。"stop" 参数指定的转义码序列在高亮
        区域之后被写入，它可以撤销 "start" 参数的效果。否则屏幕会被弄乱。

        {term-list} 可有两种形式:

        1. 转义序列的字符串。
           可以是任何字符的序列，除了不能以 "t_" 开始而且不能有空格之外。这里
           识别 <> 记号。所以你可使用 "<Esc>" 和 "<Space>"。例如:
                start=<Esc>[27h;<Esc>[<Space>r;

        2. 终端代码的列表。
           终端代码的形式是 "t_xx" ，其中 "xx" 是 termcap 项目的名字。这些代码
           必须以逗号分隔，而且不允许有空格。例如:
                start=t_C1,t_BL
           要使之工作，这些终端代码必须存在。


2. 色彩终端的高亮参数

cterm={attr-list}                                       *highlight-cterm*
        {attr-list} |attr-list| 的描述见上。"cterm" 参数可以和 "term" 不同，比
        如可以使用颜色。例如，在普通的终端上注释可以用下划线表示，在色彩终端上
        可以用蓝色显示。
        注意: 许多终端 (例如，DOS 控制台) 不能混合使用颜色和这些属性。这时，只
        用 "cterm=" 或者 "ctermfg=" 与 "ctermbg=" 两者之一。

ctermfg={color-nr}                              *highlight-ctermfg* *E421*
ctermbg={color-nr}                              *highlight-ctermbg*
        {color-nr} 参数指定颜色号。其范围从零到 termcap 项目 "Co" 给出的数字
        (不含)。实际的颜色取决于终端的类型和设置。有时，颜色也取决于 "cterm"
        的值。例如，有的系统上 "cterm=bold ctermfg=3" 给出另外一个颜色，别的系
        统上你只会得到颜色 3。

        xterm 上，它取决于你的资源，这并不容易预测。你的 xterm 文档会说明缺省
        值。color-xterm 的颜色可以通过 .Xdefaults 文件修改。不幸的是，这意味着
        每个用户未必会得到完全相同的颜色。|xterm-color| 提供带色彩的 xterm 的
        信息。

        MSDOS 的标准颜色是固定的 (在控制窗口上)，所以我们用这些名字。在 X11
        上，颜色名字的含义是固定的，所以我们用这些颜色设置，以使高亮设置可移植
        (是不是很复杂？)。下面列出这些被识别的名字和所使用的颜色号:

                                                        *cterm-colors*
            NR-16   NR-8    颜色名 
            0       0       Black (黑)
            1       4       DarkBlue (深蓝)
            2       2       DarkGreen (深绿)
            3       6       DarkCyan (深青)
            4       1       DarkRed (深红)
            5       5       DarkMagenta (深品红)
            6       3       Brown，DarkYellow (褐、深黄)
            7       7       LightGray, LightGrey，Gray, Grey (浅灰)
            8       0*      DarkGray，DarkGrey (深灰)
            9       4*      Blue，LightBlue (浅蓝)
            10      2*      Green，LightGreen (浅绿)
            11      6*      Cyan，LightCyan (浅青)
            12      1*      Red，LightRed (浅品红)
            13      5*      Magenta，LightMagenta (浅红)
            14      3*      Yellow，LightYellow (浅黄)
            15      7*      White (白)

        "NR-16" 下的数字用于 16 色的终端 ('t_Co' 大于等于 16)。"NR-8" 下的数字
        用于 8 色终端 ('t_Co' 小于 16)。'*' 表明 ctermfg 使用的时候设置 bold
        属性。在许多 8 色终端上 (比如，"linux")，它会显示增亮的颜色。但这不适
        用于背景色。如果没有 '*'，则不包含 bold 属性。如果你想用不同的方式设置
        bold 属性，在 "ctermfg=" 或 "ctermbg=" 参数_之后_设置 "cterm=" 参数。
        或者使用数字，而不是颜色名。

        忽略颜色名的大小写。
        注意 16 色 ansi 风格的终端 (包括 xterm) 使用 NR-8 一列的数字。这里，
        '*' 意味着 '加 8'，所以 Blue 成了 12，DarkGray 是 8，依此类推。

        注意 有些色彩终端下，这些名字可能会产生错误的颜色！

                                                        *:hi-normal-cterm*
        Normal 组设置的 "ctermfg" 或 "ctermbg" 颜色成为非高亮文本使用的颜色。
        例如:
                :highlight Normal ctermfg=grey ctermbg=darkblue
        设置 Normal 组的 "ctermbg" 颜色的时候，'background' 选项会自动设置。这
        使得依赖于 'background' 的高亮组发生改变！这意味着你应该先设置 Normal
        的颜色，然后再设置其它的。
        已经使用色彩方案的时候，修改 'background' 使之被重新载入，这会复位所有
        颜色 (包括 Normal)。如果你不希望如此，先删除 "colors_name" 变量。

        如果你给 Normal 组设置了 "ctermfg" 或 "ctermbg"，Vim 退出时需要复位颜
        色，这通过 "op" termcap 项目 |t_op| 完成。如果不能正确工作，尝试在你的
        .vimrc 里设置 't_op' 选项。
                                                        *E419* *E420*
        如果 Vim 知道 Normal 的前景和背景色，"fg" 和 "bg" 可以用做颜色名字。这
        只有在设置了 Normal 组的颜色以后和 (译者注: 或?) 在 MS-DOS 控制台上才
        可以。比如，设置反显视频:
            :highlight Visual ctermfg=bg ctermbg=fg
        注意 使用的颜色必须在给出命令的时候已经合法。如果之后 Normal 组的颜色
        发生改变，"fg" 和 "bg" 颜色不会被调整。


3. GUI 的高亮参数

gui={attr-list}                                         *highlight-gui*
        给出 GUI 模式适用的属性。具体描述见 |attr-list|。
        注意 这里可以使用 "bold"，也可以使用粗体字体。效果相同。
        注意 "Normal" 组的属性被忽略。

font={font-name}                                        *highlight-font*
        font-name 是字体的名字，根据 Vim 运行所在的系统而定。X11 而言，它是一
        个复杂的名字。比如:
   font=-misc-fixed-bold-r-normal--14-130-75-75-c-70-iso8859-1

        字体名 "NONE" 可以用来恢复到缺省字体。如果为 "Normal" 组设置字体，该字
        体成为缺省字体 (直到改变了 'guifont' 选项为止；使用最后设置的那个)。
        以下说明只适用于 Motif 和 Athena，不包括其它 GUI:
        设置 "Menu" 组的字体会改变菜单。设置 "Tooltip" 组的字体会改变工具提示。
        除了 Menu 和 Tooltip 的所有使用的字体必须和缺省字体的字符大小相同。否
        则，重画时会有问题。

guifg={color-name}                                      *highlight-guifg*
guibg={color-name}                                      *highlight-guibg*
guisp={color-name}                                      *highlight-guisp*
        给出 GUI 使用的前景色 (guifg)、背景色 (guibg) 和特殊颜色 (guisp)。
        "guisp" 用于 undercurl。可用一些特殊的名字:
                NONE            没有颜色 (透明)
                bg              使用 Normal 的背景色
                background      使用 Normal 的背景色
                fg              使用 Normal 的前景色
                foreground      使用 Normal 的前景色
        要使用有内嵌空格或者其它特殊字符的颜色名，把它放在单引号里面。这时，不
        能使用单引号。例如:
            :hi comment guifg='salmon pink'

                                                        *gui-colors*
        建议的颜色名 (可用于多数系统):
            Red         LightRed        DarkRed
            Green       LightGreen      DarkGreen       SeaGreen
            Blue        LightBlue       DarkBlue        SlateBlue
            Cyan        LightCyan       DarkCyan
            Magenta     LightMagenta    DarkMagenta
            Yellow      LightYellow     Brown           DarkYellow
            Gray        LightGray       DarkGray
            Black       White
            Orange      Purple          Violet

        Win32 GUI 版本可以使用更多的系统颜色。见 |win32-colors|。

        你可以用红、绿、蓝的色值指定颜色。格式为 "#rrggbb"，其中
                "rr"    为红色值
                "bb"    为蓝色值
                "gg"    为绿色值
        所有的值都以十六进制表示，范围是 "00" 到 "ff"。例如:
  :highlight Comment guifg=#11f0c3 guibg=#ff00ff

                                        *highlight-groups* *highlight-default*
有一些缺省的高亮组。'highlight' 选项缺省使用这些组。注意 高亮取决于
'background' 的值。你可以用 ":highlight" 命令看到当前的设置。
                                                        *hl-Cursor*
Cursor          光标所在的字符
                                                        *hl-CursorIM*
CursorIM        类似于 Cursor，但用于 IME 模式 |CursorIM|
                                                        *hl-CursorColumn*
CursorColumn    置位 'cursorcolumn' 时，光标所在的屏幕列
                                                        *hl-CursorLine*
CursorLine      置位 'cursorline' 时，光标所在的屏幕行
                                                        *hl-Directory*
Directory       目录名 (还有列表里的其它特殊名字)
                                                        *hl-DiffAdd*
DiffAdd         diff 模式: 增加的行 |diff.txt|
                                                        *hl-DiffChange*
DiffChange      diff 模式: 改变的行 |diff.txt|
                                                        *hl-DiffDelete*
DiffDelete      diff 模式: 删除的行 |diff.txt|
                                                        *hl-DiffText*
DiffText        diff 模式: 改变行里的改动文本 |diff.txt|
                                                        *hl-ErrorMsg*
ErrorMsg        命令行上的错误信息
                                                        *hl-VertSplit*
VertSplit       分离垂直分割窗口的列
                                                        *hl-Folded*
Folded          用于关闭的折叠的行
                                                        *hl-FoldColumn*
FoldColumn      'foldcolumn'
                                                        *hl-SignColumn*
SignColumn      显示 |signs| 的列
                                                        *hl-IncSearch*
IncSearch       'incsearch' 高亮；也用于被 ":s///c" 替换的文本
                                                        *hl-LineNr*
LineNr          ":number" 和 ":#" 命令与置位 'number' 选项时的行号，
                                                        *hl-MatchParen*
MatchParen      如果光标所在或刚刚在它之前的字符是配对的括号一部分的话，它和它
                的配对。|pi_paren.txt|

                                                        *hl-ModeMsg*
ModeMsg         'showmode' 消息 (例如，"-- INSERT --")
                                                        *hl-MoreMsg*
MoreMsg         |more-prompt|
                                                        *hl-NonText*
NonText         窗口尾部的 '~' 和 '@'，'showbreak' 的字符和其它在文本里实际不
                存在的字符 (例如，代替行尾放不下的双宽字符而显示的 ">")。
                                                        *hl-Normal*
Normal          普通文本
                                                        *hl-Pmenu*
Pmenu           弹出菜单: 普通项目。
                                                        *hl-PmenuSel*
PmenuSel        弹出菜单: 选中项目。
                                                        *hl-PmenuSbar*
PmenuSbar       弹出菜单: 滚动条。
                                                        *hl-PmenuThumb*
PmenuThumb      弹出菜单: 滚动条的拇指 (thumb)。
                                                        *hl-Question*
Question        |hit-enter| 提示和 yes/no 问题
                                                        *hl-Search*
Search          最近搜索模式的高亮 (见 'hlsearch')。也用于 quickfix 当前行的
                高亮和其它类似的要突出显示的项目。
                                                        *hl-SpecialKey*
SpecialKey      ":map" 列出的 Meta 和特殊键，也包括文本里不可显示字符的显示和
                'listchars'。
                一般的: 和实际内容显示上有差异的文本。
                                                        *hl-SpellBad*
SpellBad        拼写检查器不能识别的单词。|spell|
                它会和本来应该使用的高亮进行组合。
                                                        *hl-SpellCap*
SpellCap        应该大写字母开头的单词。|spell|
                它会和本来应该使用的高亮进行组合。
                                                        *hl-SpellLocal*
SpellLocal      拼写检查器能识别但只在其它区域使用的单词。|spell|
                它会和本来应该使用的高亮进行组合。
                                                        *hl-SpellRare*
SpellRare       拼写检查器能识别但很少使用的单词。|spell|
                它会和本来应该使用的高亮进行组合。
                                                        *hl-StatusLine*
StatusLine      当前窗口的状态行
                                                        *hl-StatusLineNC*
StatusLineNC    非当前窗口的状态行
                注意: 如果等于 "StatusLine"，Vim 会使用 "^^^" 指示当前窗口的状
                态行。
                                                        *hl-TabLine*
TabLine         分页行，非活动分页标签
                                                        *hl-TabLineFill*
TabLineFill     分页行，没有标签的地方
                                                        *hl-TabLineSel*
TabLineSel      分页行，活动分页标签
                                                        *hl-Title*
Title           ":set all"、":autocmd" 等输出的标题
                                                        *hl-Visual*
Visual          可视模式的选择区
                                                        *hl-VisualNOS*
VisualNOS       Vim 是 "选择区的非拥有者" 时，可视模式的选择区。只有 X11 GUI
                的 |gui-x11| 和 |xterm-clipboard| 才提供此支持。
                                                        *hl-WarningMsg*
WarningMsg      警告消息
                                                        *hl-WildMenu*
WildMenu        'wildmenu' 补全的当前匹配

                                        *hl-User1* *hl-User1..9* *hl-User9*
'statusline' 语法允许在状态行和标尺 (通过 'rulerformat') 上使用 9 种不同的高
亮。这些高亮组的名字是 User1 到 User9。

GUI 里，你可以使用这些组来设置菜单、滚动条和工具提示的色彩。它们没有缺省值。
这不适用于 Win32 GUI。这里，只有三种高亮参数有效: font、guibg 和 guifg。

                                                        *hl-Menu*
Menu            当前菜单的字体、背景色和前景色。也包括工具栏。
                可用的高亮参数: font、guibg、guifg。

                注意: Motif 和 Athena 里，font 参数在所有情况下实际上指定字体
                集 (fontset)，不管 'guifontset' 是否为空。所以，它和当前的
                |:language| 有关系。

                                                        *hl-Scrollbar*
Scrollbar       主窗口滚动条的当前背景和前景色。
                可用的高亮参数: guibg、guifg。

                                                        *hl-Tooltip*
Tooltip         当前工具提示的字体、背景色和前景色。也包括工具栏。
                可用的高亮参数: font、guibg、guifg。

                注意: Motif 和 Athena 里，font 参数在所有情况下都指定字体集
                (fontset)，不管 'guifontset' 是否为空，从而在设置的时候和当前
                |:language| 相联系。

13. 链接组                      *:hi-link* *:highlight-link* *E412* *E413*

如果如果你想为几个语法组使用相同的高亮设置，更简单的方法是把这些组链接到一个共
同的高亮组，并且只为该组指定颜色属性。

要设置链接:

    :hi[ghlight][!] [default] link {from-group} {to-group}

要删除链接:

    :hi[ghlight][!] [default] link {from-group} NONE

注意:                                                   *E414*
- 如果 {from-group} 和/或 {to-group} 不存在，先建立之。不存在的组不会给你错误
  信息。
- 一旦你为被链接的组使用 ":highlight" 命令，该链接关系就不存在了。
- 如果已经有 {from-group} 的高亮设置，链接不会建立，除非你给出了 '!'。如果在载
  入的文件里执行 ":highlight link" 命令，你不会得到错误信息。这可以用来跳过已
  有设置的组的链接。

                                        *:hi-default* *:highlight-default*
用 [default] 参数可以设置组的缺省高亮。如果该组已经设置了高亮，或者已经存在链
接，忽略该命令。

这里， [default] 对否决特定语法文件的高亮特别有用。例如，C 语法文件包含:
        :highlight default link cComment Comment
如果你喜欢 C 注释像 Question 一样高亮，在你的 vimrc 文件里放入此行:
        :highlight link cComment Question
如果没有 "default"，执行 C 语法文件后会覆盖你的高亮设置。

14. 清理                                                *:syn-clear* *E391*

如果你想为当前缓冲区清除所有的语法设置，可以使用如下命令:
  :syntax clear

该命令应该在你想关闭语法高亮或者切换到别的语法时使用。通常，语法文件本身不需要
它。因为载入语法文件的自动命令会清理语法。
该命令也删除 "b:current_syntax" 变量，因为该命令之后没有载入的语法了。

如果想为所有的缓冲区关闭语法高亮，你需要删除载入语法文件的自动命令:
  :syntax off

该命令实际执行的是命令
  :source $VIMRUNTIME/syntax/nosyntax.vim
详情见 "nosyntax.vim" 文件。注意 要使它工作，$VIMRUNTIME 必须合法。见
|$VIMRUNTIME|。

要为当前缓冲区清理特定的语法组:
  :syntax clear {group-name} ..
它删除了 {group-name} 里所有的模式和关键字。

要为当前缓冲区清理特定的语法组群 (簇):
  :syntax clear @{grouplist-name} ..
它把 {grouplist-name} 的内容设为空表。

                                                *:syntax-reset* *:syn-reset*
如果你修改了颜色并且把颜色弄乱了，使用这个命令取回缺省值:

  :syntax reset

它不会改变 'highlight' 选项的颜色值。

注意 你在 vimrc 文件里设定的语法颜色也会复位成其 Vim 的缺省值。
注意 如果你使用了色彩方案，色彩方案定义的语法高亮的色彩会丢失。

实际上，它做的是:

        let g:syntax_cmd = "reset"
        runtime! syntax/syncolor.vim

注意 这里使用了 'runtimepath' 选项。

                                                        *syncolor*
如果想为语法高亮使用不同的色彩，你可以增加一个 Vim 脚本来设置这些颜色。把该文
件放在 'runtimepath' 里 $VIMRUNTIME 之后的一个目录里，以使你的设置覆盖缺省颜色
值。这样，这些颜色会在 ":syntax reset" 命令之后被使用。

Unix 上你可以使用文件 ~/.vim/after/syntax/syncolor.vim。例如:

        if &background == "light"
          highlight comment ctermfg=darkgreen guifg=darkgreen
        else
          highlight comment ctermfg=green guifg=green
        endif

                                                                *E679*
要确信这个 syncolor.vim 脚本不使用 "syntax on" 命令，设置 'background' 选项或
者使用 "colorscheme" 命令，不然会导致死循环。

注意 如果使用了色彩方案，可能会比较混淆: 到底使用的是你自己定义的颜色还是方案
里的颜色。这取决于色彩方案文件，见 |:colorscheme|。

                                                        *syntax_cmd*
载入 syntax/syncolor.vim 文件时，"syntax_cmd" 变量设为以下这些值之一:
   "on"         ":syntax on" 命令。高亮颜色被覆盖，但是链接被保持
   "enable"     ":syntax enable" 命令。只为没有设置过高亮的组定义颜色。使用
                ":syntax default"。
   "reset"      ":syntax reset" 命令或者载入色彩方案。定义所有的颜色。
   "skip"       不定义颜色。用来跳过 'runtimepath' 里较早出现的 syncolor.vim
                已经设置过的缺省设置。

15. 高亮标签                                            *tag-highlight*

如果你想高亮文件里的所有标签，可以使用如下映射。

        <F11>   -- 生成 tags.vim 文件，并高亮标签。
        <F12>   -- 只根据已有的 tags.vim 文件高亮标签。

  :map <F11>  :sp tags<CR>:%s/^\([^     :]*:\)\=\([^    ]*\).*/syntax keyword Tag \2/<CR>:wq! tags.vim<CR>/^<CR><F12>
  :map <F12>  :so tags.vim<CR>

警 告: 标签文件越长，这会越慢，而 Vim 消耗的内存也越多。

这里只高亮 typedef，也可以针对 union 和 struct 进行设置。为此，你需要
Exuberant ctags (可在 http://ctags.sf.net 找到)。

在你的 Makefile 里放入以下的行:

# 建立 types 的高亮文件。需要 Exuberant ctags 和 awk
types: types.vim
types.vim: *.[ch]
        ctags -i=gstuS -o- *.[ch] |\
                awk 'BEGIN{printf("syntax keyword Type\t")}\
                        {printf("%s ", $$1)}END{print ""}' > $@

在你的 .vimrc 里放入以下的行:

   " 载入 types.vim 高亮文件，如果存在的话
   autocmd BufRead,BufNewFile *.[ch] let fname = expand('<afile>:p:h') . '/types.vim'
   autocmd BufRead,BufNewFile *.[ch] if filereadable(fname)
   autocmd BufRead,BufNewFile *.[ch]   exe 'so ' . fname
   autocmd BufRead,BufNewFile *.[ch] endif

16. 彩色 xterm                                  *xterm-color* *color-xterm*

多数彩色 xterm 只有八色。如果你得不到缺省设置的颜色，在 .vimrc 里使用这些行应
该就可以了:
   :if &term =~ "xterm"
   :  if has("terminfo")
   :    set t_Co=8
   :    set t_Sf=<Esc>[3%p1%dm
   :    set t_Sb=<Esc>[4%p1%dm
   :  else
   :    set t_Co=8
   :    set t_Sf=<Esc>[3%dm
   :    set t_Sb=<Esc>[4%dm
   :  endif
   :endif
        [<Esc> 是真正的 escape，输入 CTRL-V <Esc>]

你可能需要修改第一个 "if" 来匹配你的终端的名字。比如，"dtterm" 取代 "xterm"。

注意: 在 ":syntax on" 执行_之前_这些设置。否则颜色可能不正确。
                                                        *xiterm* *rxvt*

上面提到的设置也适用于 xiterm 和 rxvt。但要在 rxvt 里使用 16 色，可以使用
terminfo 并执行如下命令:
        :set t_AB=<Esc>[%?%p1%{8}%<%t25;%p1%{40}%+%e5;%p1%{32}%+%;%dm
        :set t_AF=<Esc>[%?%p1%{8}%<%t22;%p1%{30}%+%e1;%p1%{22}%+%;%dm

                                                        *colortest.vim*
要测试你的色彩设置，Vim 发布版本里包含了一个文件。要使用它，执行如下命令:
   :runtime syntax/colortest.vim

即使颜色数定义为 8，一些版本的 xterm (还有其他终端，比如 linux 控制台) 可以输
出更亮的前景色。因此如果 't_Co' 为 8，Vim 为浅色的前景色设置 "cterm=bold" 属
性。

                                                        *xfree-xterm*
要得到 16 色或更多，需要最新的 xterm 版本 (应该包含在 Xfree86 3.3 或更新的版本
里)。你可以在这里得到最新的版本:
        http://invisible-island.net/xterm/xterm.html
下面是 configure 的好方法。它使用 88 色，并打开 termcap-query 特性。这使得 Vim
能够询问 xterm 可以支持多少颜色。
        ./configure --disable-bold-color --enable-88-color --enable-tcap-query
如果你只有 8 色，检查 xterm 的编译设置。
(另见 |UTF8-xterm|，了解如何在该 xterm 里使用 UTF-8 字符编码)。

在你的 .vimrc 放入以下几行，该 xterm 应该工作 (16 色):
   :if has("terminfo")
   :  set t_Co=16
   :  set t_AB=<Esc>[%?%p1%{8}%<%t%p1%{40}%+%e%p1%{92}%+%;%dm
   :  set t_AF=<Esc>[%?%p1%{8}%<%t%p1%{30}%+%e%p1%{82}%+%;%dm
   :else
   :  set t_Co=16
   :  set t_Sf=<Esc>[3%dm
   :  set t_Sb=<Esc>[4%dm
   :endif
        [<Esc> 是真正的 escape，输入 CTRL-V <Esc>]

没有 |+terminfo| 的话，Vim 会识别这些设置，并自动把 cterm 的第 8 色或更高的颜
色翻译成 "<Esc>[9%dm" 和 "<Esc>[10%dm"。第 16 色以上也自动进行翻译。

有报告说这样可以用于 256 色:

   :set t_AB=<Esc>[48;5;%dm
   :set t_AF=<Esc>[38;5;%dm

或者只设置 TERM 环境变量为 "xterm-color" 或 "xterm-16color"，然后试试行不行。

你也许想使用如下 X 资源 (在你的 ~/.Xdefaults 文件里):
        XTerm*color0:                   #000000
        XTerm*color1:                   #c00000
        XTerm*color2:                   #008000
        XTerm*color3:                   #808000
        XTerm*color4:                   #0000c0
        XTerm*color5:                   #c000c0
        XTerm*color6:                   #008080
        XTerm*color7:                   #c0c0c0
        XTerm*color8:                   #808080
        XTerm*color9:                   #ff6060
        XTerm*color10:                  #00ff00
        XTerm*color11:                  #ffff00
        XTerm*color12:                  #8080ff
        XTerm*color13:                  #ff40ff
        XTerm*color14:                  #00ffff
        XTerm*color15:                  #ffffff
        Xterm*cursorColor:              Black

[注意: 需要 cursorColor 来绕过一个漏洞。该漏洞把光标颜色设为最后显示的文本的颜
色。在较新的版本里该问题被修正，但还不是所有人都使用新版本。]

要立刻使用，在 X 选项数据库管理器里重新载入 .Xdefaults 文件 (你只须在改变
.Xdefaults 文件的时候这么做就可以了):
  xrdb -merge ~/.Xdefaults

                                        *xterm-blink* *xterm-blinking-cursor*
要使光标在 xterm 上闪烁，见 tools/blink.c。或者使用 Thomas Dickey 的 xterm 补
丁号 107 以上的版本 (取得的方法见上)，使用这些资源:
        XTerm*cursorBlink:      on
        XTerm*cursorOnTime:     400
        XTerm*cursorOffTime:    250
        XTerm*cursorColor:      White

                                                        *hpterm-color*
下面的设置 (或多或少) 在 hpterm 里工作，它只支持 8 种前景色:
   :if has("terminfo")
   :  set t_Co=8
   :  set t_Sf=<Esc>[&v%p1%dS
   :  set t_Sb=<Esc>[&v7S
   :else
   :  set t_Co=8
   :  set t_Sf=<Esc>[&v%dS
   :  set t_Sb=<Esc>[&v7S
   :endif
        [<Esc> 是真正的 escape，输入 CTRL-V <Esc>]

                                                *Eterm* *enlightened-terminal*
有报告称下面的设置可以使得 Enlightened terminal emulator，或 Eterm，工作。它们
可能适用于所有的和 xterm 类似并使用 bold 属性来取得亮色的终端。有必要的话，增
加类似于上面那样的 ":if"。
       :set t_Co=16
       :set t_AF=^[[%?%p1%{8}%<%t3%p1%d%e%p1%{22}%+%d;1%;m
       :set t_AB=^[[%?%p1%{8}%<%t4%p1%d%e%p1%{32}%+%d;1%;m

                                                *TTpro-telnet*
下面的设置应该适用于 TTpro telnet。Tera Term Pro 是 MS-Windows 上一个自由软件
/ 开源程序。
        set t_Co=16
        set t_AB=^[[%?%p1%{8}%<%t%p1%{40}%+%e%p1%{32}%+5;%;%dm
        set t_AF=^[[%?%p1%{8}%<%t%p1%{30}%+%e%p1%{22}%+1;%;%dm
要确信打开了 TTpro 的 Setup / Window / Full Color，并确信_没有_打开 Setup /
Font / Enable Bold。
(由 John Love-Jensen <eljay@Adobe.COM> 提供信息)

 vim:tw=78:sw=4:ts=8:ft=help:norl:
Generated by vim2html on 2006年 06月 24日 星期六 00:27:59 UTC

























