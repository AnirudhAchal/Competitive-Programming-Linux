for((i = 1;; i++)); do
    echo $i
    ./A < test1.txt > out1
    ./B < test1.txt > out2
    diff -w out1 out2 || break
done
