# 自动打印代码
import datetime
import os
import sys
import shutil

header = r"""
\documentclass{article}
\usepackage{amsmath}
\usepackage{minted}
\usepackage{fontspec}
\usepackage{xeCJK}
\usepackage{titlesec}
\usepackage{hyperref}

\newcommand{\sectionbreak}{\clearpage}
\newcommand{\subsectionbreak}{\clearpage}
\setmonofont{Fantasque Sans Mono}
\setCJKmainfont{Microsoft YaHei}
\setCJKmonofont{Microsoft YaHei}
\setminted[cpp]{mathescape, linenos, breaklines}

\title{Wellgasa Code Snippets}
\date{\today}
\author{Wellgasa Team}

\begin{document}
  \maketitle
  \newpage

  \tableofcontents
  \newpage
"""

footer = r"""
\end{document}
"""

os.chdir(sys.path[0])

if os.path.exists("dist"):
    shutil.rmtree("dist")
os.makedirs("dist")
os.chdir("dist")

dic = {}

for root, dirs, files in os.walk('..', topdown=True):
    dirs[:] = [d for d in dirs if d[0] != '.']
    for f in files:
        if(f.endswith(".cpp")):
            dic.setdefault(root, []).append(f)

with open('out.tex', 'w') as fh:
    fh.write("% Auto Generated on " + datetime.datetime.today().isoformat(' '))
    fh.write(header)
    for d in dic:
        fh.write("""
        \\section{%s}
        """ % d.split('\\')[-1])
        for f in dic[d]:
            fh.write("""
            \\subsection{%s}
            \\inputminted{cpp}{%s}
            """ % (f.split('.')[0], os.path.join(d, f).replace('\\', '/')))
    fh.write(footer)

os.system("xelatex -shell-escape out.tex")
os.system("xelatex -shell-escape out.tex")
