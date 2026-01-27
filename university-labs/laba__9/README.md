# Оценка 3

## 1-4

![alt text](images/image1.png)
![alt text](images/image2.png)
- с помощью git log мы получаем историю коммитов репозитория programming
- после того как я добавил файл sort.c он начал отображаться в git status как не отслеживаемый

## 5-8

![alt text](images/image3.png)
- после добавления файлов в stage git status укказывает на те файлы которые попадут в следующий коммит
- после того как мы закоммитили в git statuse показывает что нам нечего коммитить и можно пушить

## 9-12

![alt text](images/image4.png)
- комментарий будет добавлен в индекс (staging area) для следующего коммита.
- после добавления появляется перечень файлов которые будут в следующем коммите

## 13-17

![alt text](images/image5.png)
- в git status теперь показывает непроиндесированные изменения (второй комментарий в sort.c) и то что ветка main опережает origin/main на 2 коммита

# Ветки

## 1-5

![alt text](images/image6.png)
- команда git checkout -b создает новую ветку и переключается на нее, а git status и git branch показывают нам что мы находимся на ветке mybranch

## 6-10

![alt text](images/image7.png)
- находясь на нашей новой метке git log показывает нам коммит на этой ветке и то что мы находимся на ней
- после того как мы вернулись на ветку main мы перестаем видеть нашу созданную ветку mybranch

## 11-14

![alt text](images/image8.png)
- наш файл file2.txt не удаляется а остается в ветке master

## 15-17
![alt text](images/image9.png)
- git diff показал разницу между двумя ветками


# Оценка 4

## 1-4
![alt text](images/image10.png)
- git diff --staged пустой тк в стедже ничего нет
- git diff показывает изменения в файле

## 5-7
![alt text](images/image11.png)
- после использования команды git diff мы ничего не видим,а git diff --staged указывает на проиндексированные изменения которые до этого были в git diff

## 8-11
![alt text](images/image12.png)
![alt text](images/image13.png)
- git diff указывает на отличия между проиндексированным и непроиндексированными файлами
- после добавления в stage команда git diff --stage также показывает нам различия

## 12-14
![alt text](images/image14.png)
- сначала в git status мы видим проиндексированные изменения и непроиндексированые, но после отмены индексации мы видим только непроиндексированные

## 15-16
![alt text](images/image15.png)
- появился только что сделанный нами коммит

## 17-19
![alt text](images/image16.png)
![alt text](images/image17.png)
- добавил в файл sort.c print("hello git\n");
- git status показывает нам непроиндексированные изменения

## 20-23
![alt text](images/image18.png)
![alt text](images/image19.png)
- после использования git restore файл sort.c вернулся до состояния добавления printf("hello git\n");
- git status говорит об отсутсвии изменений

# Ветки и ff-merge

## 1-5
![alt text](images/image20.png)
- создал новый файл по заданию и добавил туда строку hello
- создал новую ветку и перешел в нее, с помощью git status видим что нет изменений

## 6-9
![alt text](images/image21.png)
- git branch показывает нам все ветки и выдялет ту на которой мы находимся
- git log --oneline --graph --all выводит все наше дерево коммитов 

## 10-12
![alt text](images/image22.png)
![alt text](images/image23.png)
- cat в ветке main выводит HELLO, а git diff показывает разницу написания  hello/HELLO в зависимости от ветки

## 13-19
![alt text](images/image24.png)
