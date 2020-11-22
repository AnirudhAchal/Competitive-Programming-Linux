for((i=1; i<=20; i++)); do
    input1="randI"
    input2=$i
    input3=".txt"
    output1="input"
    output2=$((i+30))
    output3=".txt"
    
    input="${input1}${input2}${input3}"
    output="${output1}${output2}${output3}"

    echo $input
    echo $output

    mv $input $output
done
