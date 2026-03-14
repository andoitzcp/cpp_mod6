#!/usr/bin/env sh

echo "===== This tests should fail ====="
echo 'testing command: ./convert ""'
./convert ""
echo 'testing command: ./convert "a"'
./convert "a"
echo 'testing command: ./convert "asdf"'
./convert "asdf"
echo 'testing command: ./convert "12asdf"'
./convert "12asdf"
echo 'testing command: ./convert "a12sdf"'
./convert "a12sdf"
echo 'testing command: ./convert "a1sdf"'
./convert "a1sdf"
echo 'testing command: ./convert "asdf12"'
./convert "asdf12"
echo 'testing command: ./convert "asdasdjf;lja;lkf;ldsajflk;sdjfa;lkjdsj"'
./convert "asdasdjf;lja;lkf;ldsajflk;sdjfa;lkjdsj"
echo 'testing command: ./convert 12.12.12'
./convert 12.12.12

echo "===== This tests should success ====="
echo 'testing command: ./convert 0'
./convert 0
echo 'testing command: ./convert 1'
./convert 1
echo 'testing command: ./convert -1'
./convert -1
echo 'testing command: ./convert 123'
./convert 123
echo 'testing command: ./convert -123'
./convert -123
echo 'testing command: ./convert 123f'
./convert 123f
echo 'testing command: ./convert -123f'
./convert -123f
echo 'testing command: ./convert 42.00'
./convert 42.00
echo 'testing command: ./convert -42.00'
./convert -42.00
echo 'testing command: ./convert 42.00f'
./convert 42.00f
echo 'testing command: ./convert -42.00f'
./convert -42.00f
echo 'testing command: ./convert 999999999999999'
./convert 999999999999999
echo 'testing command: ./convert -999999999999999'
./convert -999999999999999
echo 'testing command: ./convert 999999999999999999999999999999999999999999999'
./convert 999999999999999999999999999999999999999999999
echo 'testing command: ./convert -99999999999999999999999999999999999999999999'
./convert -99999999999999999999999999999999999999999999
echo 'testing command: ./convert 999999999999999999999999999999999999999999999.999'
./convert 999999999999999999999999999999999999999999999.999
echo 'testing command: ./convert -99999999999999999999999999999999999999999999.999'
./convert -99999999999999999999999999999999999999999999.999
echo 'testing command: ./convert .99'
./convert .99
echo 'testing command: ./convert -.99'
./convert -.99
echo 'testing command: ./convert .99f'
./convert .99f
echo 'testing command: ./convert nan'
./convert nan
echo 'testing command: ./convert +inf'
./convert +inf
echo 'testing command: ./convert -inf'
./convert -inf
