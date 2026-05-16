package laba18__test

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_fibonacci_different_cases(t *testing.T) {
	
	res1, err1 := Fibonacci(0, 100)
	assert.NoError(t, err1, "Fibonacci(0, 100) не должен возвращать ошибок")
	assert.Equal(t, 0, res1, "Fibonacci(0, 100): Ожидалось = 0, получено = %d", res1)

	res2, err2 := Fibonacci(1, 100)
	assert.NoError(t, err2, "Fibonacci(1, 100) не должен возвращать ошибок")
	assert.Equal(t, 1, res2, "Fibonacci(1, 100): Ожидалось = 1, получено = %d", res2)

	res3, err3 := Fibonacci(2, 100)	
    assert.NoError(t, err3, "Fibonacci(2, 100) не должен возвращать ошибок")
    assert.Equal(t, 1, res3, "Fibonacci(2, 100): Ожидалось = 1, получено = %d", res3)
    
    res4, err4 := Fibonacci(5, 100)
    assert.NoError(t, err4, "Fibonacci(5, 100) не должен возвращать ошибок")
    assert.Equal(t, 5, res4, "Fibonacci(5, 100): Ожидалось = 5, получено = %d", res4)
    
    res5, err5 := Fibonacci(10, 100)
    assert.NoError(t, err5, "Fibonacci(10, 100) не должен возвращать ошибок")
    assert.Equal(t, 55, res5, "Fibonacci(10, 100): Ожидалось = 55, получено = %d", res5)

}

func Test_fibonacci_edge_cases(t *testing.T) {

	res1, err1 := Fibonacci(-10, 100)
	
	assert.Error(t, err1, "Fibonacci(-10, 100) должен вернуть ошибку из за отрицатеьльного числа")
	assert.Equal(t, 0, res1, "Fibonacci(-10, 100): Ожидаемый результат = 0, полученный = %d", res1)

	res2, err2 := Fibonacci(30, 10)
	assert.Error(t, err2, "Fibonacci(30, 10) должен вернуть ошибку из за srart > end")
	assert.Equal(t, 0, res2, "Fibonacci(30, 10): Ожидаемый результат = 0, полученный = %d", res2)

}

func Test_fibonacci_subsequence(t *testing.T) {

	fibonacci_subsequence := []int{0, 1, 1, 2, 3, 5, 8, 13}

	for i := 0; i < len(fibonacci_subsequence); i++ {
		res, err := Fibonacci(i, 100)
		assert.NoError(t, err, "Fibonacci(%d, 100) не должен возвращать ошибку", i)

		assert.Equal(t, fibonacci_subsequence[i], res, "Fibonacci(%d, 100): Ожидалось = %d, получено = %d", i, fibonacci_subsequence[i], res)
	}

}

func Test_fibonacci_max(t *testing.T) {

	res, err := Fibonacci(2, 0)
	assert.Error(t, err, "Fibonacci(2, 0) ожидалось вывода ошибки, но этого не произошло")
	assert.Equal(t, 0, res, "Fibonacci(2, 0): Ожидалось получить = 0, получилось = %d", res)

	res2, err2 := Fibonacci(1, 0)
	assert.NoError(t, err2, "Fibonacci(1, 0) ошибки быть не должно")
	assert.Equal(t, 1, res2, "Fibonacci(1, 0): Ожидалось получить = 1, получилось = %d", res2)

}