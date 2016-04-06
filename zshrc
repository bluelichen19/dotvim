# Path to your oh-my-zsh installation.
export ZSH=/Users/zhenghaishu/.oh-my-zsh

# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
#ZSH_THEME="robbyrussell"
ZSH_THEME="agnoster"
#ZSH_THEME="powerline"

#自定义
#自动补全
autoload -U compinit promptinit
compinit
#
#添加下面的配置可以启动使用方向键控制的自动补全：
zstyle ':completion:*' menu select
#
#按两次 tab 键启动菜单
#添加下面的配置可以启动命令行别名的自动补全：
setopt completealiases
#
#source $ZSH/oh-my-zsh.sh
# number of lines kept in history
export HISTSIZE=10000
# # number of lines saved in the history after logout
export SAVEHIST=10000
# # location of history
export HISTFILE=~/.zhistory
# # append command to history file once executed
setopt INC_APPEND_HISTORY
#mvim start
alias vm="mvim -f"
alias v="mvim -v"
alias tmux='tmux -2'
#alias v="vim -v "
#alias vm="mvim -f "
#alias vim='VIM --servername VIM'
#mvim end
#全屏下每个独立shell，启用各自历史
#mkdir -p $HOME/.zsh_history$PWD
#export HISTFILE="$HOME/.zsh_history$PWD/zhistory"

#cd() {
#    builtin cd "$@"
#    fc -W
#    local HISTDIR="$HOME/.zsh_history$PWD"
#    if  [ ! -d "$HISTDIR" ] ; then
#        mkdir -p "$HISTDIR"
#    fi
#    export HISTFILE="$HISTDIR/zhistory"
#    touch $HISTFILE
#    local ohistsize=$HISTSIZE
#    HISTSIZE=0
#    HISTSIZE=$ohistsize
#    fc -R
#}

#function allhistory {
#    cat $(find $HOME/.zsh_history -name zhistory)
#}

#function convhistory {
#    sort $1 | uniq |
#    sed 's/^:\([ 0-9]*\):[0-9]*;\(.*\)/\1::::::\2/' |
#    awk -F"::::::" '{ $1=strftime("%Y-%m-%d %T",$1) "|"; print }' 
#}

#function histall {
#    convhistory =(allhistory) | sed '/^.\{20\} *cd/i\\'
#}

#function hist {
#    convhistory $HISTFILE
#}
 
#function top50 {
#    allhistory | awk -F':[ 0-9]*:[0-9]*;' '{ $1="" ; print }'\
#        | sed 's/ /\n/g' | sed '/^$/d' | sort | uniq -c | sort -nr | head -n 50
#}
[[ -s $(brew --prefix)/etc/profile.d/autojump.sh ]] && . $(brew --prefix)/etc/profile.d/autojump.sh
#export VIM="/usr/local/Cellar/macvim/HEAD/MacVim.app/Contents/Resources/vim:/usr/local/Cellar/macvim/HEAD:$VIM"
#export VIM="/usr/local/Cellar/macvim/HEAD/MacVim.app/Contents/Resources/vim:$VIM"
#export PATH="/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/eclipse/Eclipse.app/Contents/MacOS:/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools:usr/local/bin:usr/local/sbin:/Users/zhenghaishu/bin:/usr/local/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Users/zhenghaishu/work/develop/android_ndk/android-ndk-r9d"
# export MANPATH="/usr/local/man:$MANPATH"
#/usr/local/Cellar/macvim/HEAD/MacVim.app/Contents/Resources/vim
#function postCallVim
#{
#  osascript -e 'tell application "MacVim" to activate'
#}
#自定义

POWERLINE_RIGHT_A=""
POWERLINE_RIGHT_B=""

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion. Case
# sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# The optional three formats: "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load? (plugins can be found in ~/.oh-my-zsh/plugins/*)
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git sudo autojump)
[[ -s ~/.autojump/etc/profile.d/autojump.sh ]] && . ~/.autojump/etc/profile.d/autojump.sh
#plugins=(vim-interaction)

# User configuration
#export PATH="/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools"
#export PATH="/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/eclipse/Eclipse.app/Contents/MacOS:/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools:usr/local/bin:usr/local/sbin:/Users/zhenghaishu/bin:/usr/local/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Users/zhenghaishu/work/develop/android_ndk/android-ndk-r9d"
# export MANPATH="/usr/local/man:$MANPATH"

#修改成对应的
#export PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/Users/zhenghaishu/work/develop/android-ndk-r10e/android-ndk-r10e:/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools:/Users/zhenghaishu/work/develop/android-ndk-r10e/android-ndk-r10e/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin

source $ZSH/oh-my-zsh.sh

# You may need to manually set your language environment
export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

#mvim start
#alias vim=/Applications/MacVim.app/Contents/MacOS/MacVim
#mvim end

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/dsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"


# Path to your oh-my-zsh configuration.
ZSH=$HOME/.oh-my-zsh

# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
#ZSH_THEME="ducknorris"

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

#alias my="/usr/local/mysql/bin/mysql"
#alias c="/usr/local/bin/cloc"
#alias s="/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl"
#alias p="/usr/local/Cellar/python/2.7.5/bin/python"

alias gpall="git pushall"

COMPLETION_WAITING_DOTS="true"

plugins=(git brew rails3 git-flow capistrano zeus)

#source $ZSH/oh-my-zsh.sh

export PATH=/Users/ducky/.rvm/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin

if [[ -s "/Users/ducky/.rvm/scripts/rvm" ]] ; then source "/Users/ducky/.rvm/scripts/rvm" ; fi



#关于历史纪录的配置 {{{
#历史纪录条目数量
export HISTSIZE=10000
#注销后保存的历史纪录条目数量
export SAVEHIST=10000
#历史纪录文件
export HISTFILE=~/.zhistory
#以附加的方式写入历史纪录
setopt INC_APPEND_HISTORY
#如果连续输入的命令相同，历史纪录中只保留一个
setopt HIST_IGNORE_DUPS
#为历史纪录中的命令添加时间戳
setopt EXTENDED_HISTORY      
 
#启用 cd 命令的历史纪录，cd -[TAB]进入历史路径
setopt AUTO_PUSHD
#相同的历史路径只保留一个
setopt PUSHD_IGNORE_DUPS
 
#在命令前添加空格，不将此命令添加到纪录文件中
#setopt HIST_IGNORE_SPACE
#}}}

#每个目录使用独立的历史纪录{{{
cd() {
builtin cd "$@"                             # do actual cd
fc -W                                       # write current history  file
local HISTDIR="$HOME/.zsh_history$PWD"      # use nested folders for history
if  [ ! -d "$HISTDIR" ] ; then          # create folder if needed
mkdir -p "$HISTDIR"
fi
export HISTFILE="$HISTDIR/zhistory"     # set new history file
touch $HISTFILE
local ohistsize=$HISTSIZE
HISTSIZE=0                              # Discard previous dir's history
HISTSIZE=$ohistsize                     # Prepare for new dir's history
fc -R                                       #read from current histfile
}
mkdir -p $HOME/.zsh_history$PWD
export HISTFILE="$HOME/.zsh_history$PWD/zhistory"
 
function allhistory { cat $(find $HOME/.zsh_history -name zhistory) }
function convhistory {
sort $1 | uniq |
sed 's/^:\([ 0-9]*\):[0-9]*;\(.*\)/\1::::::\2/' |
awk -F"::::::" '{ $1=strftime("%Y-%m-%d %T",$1) "|"; print }'
}
#使用 histall 命令查看全部历史纪录
function histall { convhistory =(allhistory) |
sed '/^.\{20\} *cd/i\\' }
#使用 hist 查看当前目录历史纪录
function hist { convhistory $HISTFILE }
 
#全部历史纪录 top50
function top50 { allhistory | awk -F':[ 0-9]*:[0-9]*;' '{ $1="" ; print }' | sed 's/ /\n/g' | sed '/^$/d' | sort | uniq -c | sort -nr | head -n 50 }
 
#}}}
 
#杂项 {{{
#允许在交互模式中使用注释  例如：
#cmd #这是注释
setopt INTERACTIVE_COMMENTS      
 
#启用自动 cd，输入目录名回车进入目录
#稍微有点混乱，不如 cd 补全实用
setopt AUTO_CD
 
#扩展路径
#/v/c/p/p => /var/cache/pacman/pkg
setopt complete_in_word
 
#禁用 core dumps
limit coredumpsize 0

#}}}

#以下字符视为单词的一部分
WORDCHARS='*?_-[]~=&;!#$%^(){}<>'
#}}}
 
#自动补全功能 {{{
setopt AUTO_LIST
setopt AUTO_MENU
#开启此选项，补全时会直接选中菜单项
#setopt MENU_COMPLETE
 
autoload -U compinit
compinit
 
#自动补全缓存
#zstyle ':completion::complete:*' use-cache on
#zstyle ':completion::complete:*' cache-path .zcache
#zstyle ':completion:*:cd:*' ignore-parents parent pwd
 
#自动补全选项
zstyle ':completion:*' verbose yes
zstyle ':completion:*' menu select
zstyle ':completion:*:*:default' force-list always
zstyle ':completion:*' select-prompt '%SSelect:  lines: %L  matches: %M  [%p]'
 
zstyle ':completion:*:match:*' original only
zstyle ':completion::prefix-1:*' completer _complete
zstyle ':completion:predict:*' completer _complete
zstyle ':completion:incremental:*' completer _complete _correct
zstyle ':completion:*' completer _complete _prefix _correct _prefix _match _approximate
 
#路径补全
zstyle ':completion:*' expand 'yes'
zstyle ':completion:*' squeeze-shlashes 'yes'
zstyle ':completion::complete:*' '\\'
 
#彩色补全菜单
#eval $(dircolors -b)
#export ZLSCOLORS="${LS_COLORS}"
#zmodload zsh/complist
#zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
#zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
 
#修正大小写
zstyle ':completion:*' matcher-list '' 'm:{a-zA-Z}={A-Za-z}'
#错误校正
zstyle ':completion:*' completer _complete _match _approximate
zstyle ':completion:*:match:*' original only
zstyle ':completion:*:approximate:*' max-errors 1 numeric
 
#kill 命令补全
compdef pkill=kill
compdef pkill=killall
zstyle ':completion:*:*:kill:*' menu yes select
zstyle ':completion:*:*:*:*:processes' force-list always
zstyle ':completion:*:processes' command 'ps -au$USER'
 
#补全类型提示分组
zstyle ':completion:*:matches' group 'yes'
zstyle ':completion:*' group-name ''
zstyle ':completion:*:options' description 'yes'
zstyle ':completion:*:options' auto-description '%d'
zstyle ':completion:*:descriptions' format $'\e[01;33m -- %d --\e[0m'
zstyle ':completion:*:messages' format $'\e[01;35m -- %d --\e[0m'
zstyle ':completion:*:warnings' format $'\e[01;31m -- No Matches Found --\e[0m'
zstyle ':completion:*:corrections' format $'\e[01;32m -- %d (errors: %e) --\e[0m'
 
# cd ~ 补全顺序
zstyle ':completion:*:-tilde-:*' group-order 'named-directories' 'path-directories' 'users' 'expand'
#}}}
 
##行编辑高亮模式 {{{
# Ctrl+@ 设置标记，标记和光标点之间为 region
zle_highlight=(region:bg=magenta #选中区域
special:bold      #特殊字符
isearch:underline)#搜索时使用的关键字
#}}}
 
##空行(光标在行首)补全 "cd " {{{
user-complete(){
case $BUFFER in
"" )                       # 空行填入 "cd "
BUFFER="cd "
zle end-of-line
zle expand-or-complete
;;
"cd --" )                  # "cd --" 替换为 "cd +"
BUFFER="cd +"
zle end-of-line
zle expand-or-complete
;;
"cd +-" )                  # "cd +-" 替换为 "cd -"
BUFFER="cd -"
zle end-of-line
zle expand-or-complete
;;
* )
zle expand-or-complete
;;
esac
}
zle -N user-complete
bindkey "\t" user-complete
#}}}
