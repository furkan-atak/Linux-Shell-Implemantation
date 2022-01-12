# Linux-Shell-Implemantation
Basic Linux Shell Implemantation. using C

“bash” komutu girildiğinde sistemdeki bash programı çağırılmaktadır ve bashteki normal işlemler
yapılabilmektedir. Bu bash’e exit yazılana kadar diğer ana prosess beklenmektedir.
o myshell>> bash
o bash>>echo xxx
o xxx
o bash>> exit
o myshell>>
 “tekrar” programı bir adet string ve bir adet pozitif rakam
parametresi almaktadır.
o myshell>> tekrar this 3
o this
o this
o this
Bu programın çağırılması sonucunda shell beklemez sonuç gelince yazdırır.
 shell üzerinde çalışan “islem” “topla” ve “cikar” olarak üç adet program mevcuttur. Bu programlardan “islem” diğer iki
programı çağıracaktır. “islem” myshell’den 3 parametre alarak çalışır ve çıktıları myshell
yazar. “islem” programı gelen parametreye göre prosese “topla” veya “cikar” programlarını
yükler.
o myshell>> islem cikar 4 2
o 4 - 2 = 2
