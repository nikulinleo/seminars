Программа учета покупок в магазине

Для сборки используйте make clean && make all

После запуска программа ожидает описание действия:
	buy - описание покупки товаров
		допустимо использовать buy (productname) - в таком случае (productname) сразу будет считано как имя продукта
		и будет предложено перейти к вводу цены и количества товаров

		цена должна быть строго больше 0, а количество - больше или равно 0
		в противном случае будет повторная попытка ввода чисел

	check - вывод списка уже купленных товаров

	end - вывод списка покупок и завершение