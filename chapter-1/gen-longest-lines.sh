perl -E 'say " "x50' > longest-lines.txt
perl -E 'say("-"x(int(rand(100))+1)." "x(int(rand(5))+1)) for 1..(int(rand(50))+1)' >> longest-lines.txt
perl -E 'say "-"x1010' >> longest-lines.txt
