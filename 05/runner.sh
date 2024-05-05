i=2
while [ $i -le 1024 ]
do
    str=$(time ./zda $i alf.txt trgt.txt 2>&1)
    echo $str >> results.txt
    i=$((i*i))
done