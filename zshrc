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
plugins=(git sudo)
#plugins=(vim-interaction)

# User configuration
#export PATH="/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools"
#export PATH="/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/eclipse/Eclipse.app/Contents/MacOS:/Users/zhenghaishu/work/develop/adt-bundle-mac-x86_64-20140321/sdk/platform-tools:usr/local/bin:usr/local/sbin:/Users/zhenghaishu/bin:/usr/local/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Users/zhenghaishu/work/develop/android_ndk/android-ndk-r9d"
# export MANPATH="/usr/local/man:$MANPATH"

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
