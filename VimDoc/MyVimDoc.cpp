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
"    -> pathogen插件 
"    ->  
"    ->  
"    ->  
"    ->  
"    ->  
"    ->  
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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => pathogen插件 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
scriptnames 显示插件启动顺序

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


























