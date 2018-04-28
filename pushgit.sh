#########################################################################
# File Name: pushgit.sh
# Author: zhangk
# mail: 907144187@qq.com
# Created Time: Sat 28 Apr 2018 12:13:39 AM PDT
#########################################################################
#!/bin/bash

git add .
git commit -m $1
git push origin master
