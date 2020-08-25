for((i = 1;; i++)); do
    echo $i
    ./gen $i > int
    ./CP_Template < int > out1
    ./brute < int > out2
    diff -w out1 out2 || break
done
