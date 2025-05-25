gcc -Wall -Wextra -Werror ../s21_cat.c -o s21_cat


test_num=0
fail_count=0
succ_count=0
opts=(-b -e -n -s -t)
files=("text1.txt" "text2.txt" "text3.txt" "text4.txt" "text5.txt" "text1.txt text2.txt" "text1.txt text2.txt text3.txt" "text1.txt text2.txt text3.txt text4.txt text5.txt")

for opt in ${opts[@]}
do
    for file in ${files[@]}
    do 
        echo "Test $test_num:"
        ./s21_cat $opt $file > s21_cat_res
        cat $opt $file > cat_res
        if [[ $(diff -q cat_res s21_cat_res) ]]
        then 
            echo "Failed at 's21_cat $opt $file'\n"
            fail_count=$((fail_count + 1))
        else
            echo "Success\n"
            succ_count=$((succ_count + 1))
        fi
        test_num=$((test_num + 1))
    done
done

if [ $fail_count == 0 ]
    then 
        echo "\nSuccess, $succ_count/$test_num done\n"
    else
        echo "\nFailed, $fail_count/$test_num error(s)\n"
fi

rm -rf cat_res s21_cat_res s21_cat