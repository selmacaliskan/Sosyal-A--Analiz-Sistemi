# Arkadaşlık Ağı Yönetimi (Friendship Network Management)

Bu C programı, bir arkadaşlık ağı simülasyonu oluşturur. Kullanıcılar arasında arkadaşlık ilişkileri kurar, ortak arkadaşları bulur, toplulukları keşfeder ve en etkili kullanıcıyı (en fazla kişiye ulaşabilen) tespit eder. Program, kullanıcı verilerini bir dosyadan okur ve çeşitli ağ işlemleri gerçekleştirebilir.

## Özellikler

**Kullanıcılar ve Arkadaşlar:** Kullanıcılar oluşturulabilir ve birbirlerine arkadaşlıklar eklenebilir.

**Arkadaşlık Mesafesi:** Belirli bir kullanıcının arkadaşlarının belirli bir mesafeye kadar olanlarını bulma.

**Ortak Arkadaşlar:** İki kullanıcı arasındaki ortak arkadaşları bulma.

**Topluluklar:** Kullanıcılar arasındaki arkadaşlık ilişkilerine dayanarak, topluluklar (bağlantılı bileşenler) tespit edilir.

**Etkili Kullanıcı:** Arkadaşlık ağı üzerinde en fazla kişiye ulaşabilen (etkili) kullanıcı bulunur.

## 📁Dosya Formatı

Program, kullanıcı ve arkadaşlık bilgilerini `veriseti.txt` adlı bir dosyadan okur. Dosya formatı aşağıdaki gibi olmalıdır:


**`USER <user_id>`** komutu yeni bir kullanıcı oluşturur.

**`FRIEND <user_id1> <user_id2>`** komutu, iki kullanıcıyı arkadaş yapar.


## Kullanıcı Fonksiyonları

**add_user(int id):** Yeni bir kullanıcı ekler.

**add_friend(int id1, int id2):** İki kullanıcıyı arkadaş yapar.

**find_friends_at_distance(int start_id, int distance):** Bir kullanıcıdan belirli bir mesafede bulunan arkadaşları bulur.

**find_common_friends(int id1, int id2):** İki kullanıcı arasındaki ortak arkadaşları bulur.

**find_communities():** Ağdaki toplulukları (bağlantılı bileşenleri) tespit eder.

**find_influential_user():** En fazla kişiye ulaşabilen kullanıcıyı bulur.


### Veri Dosyasını Hazırlama

Kullanıcıları ve arkadaşlık ilişkilerini içeren bir `veriseti.txt` dosyası oluşturun.

### Programı Çalıştırma

Aşağıdaki komutu kullanarak programı çalıştırın:

```bash
gcc -o friendship_network friendship_network.c
./friendship_network
 ```



## Sonuçlar
Program, kullanıcılar ve arkadaşlar hakkında bilgiler yazdıracak ve ayrıca kullanıcıların ağ üzerindeki etkilerini analiz edecektir.

### Örnek Çıktılar
Kullanıcılar ve Arkadaşlar:


Kullanici 101: 102 103
Kullanici 102: 101
Kullanici 103: 101
101 Kullanıcısının 2 Adım Uzaklıktaki Arkadaşları:


Kullanici 101 icin 2 adim uzakliktaki arkadaslar: 103
Ortak Arkadaşlar:


Kullanici 101 ve Kullanici 102 icin ortak arkadaslar: 103
Kullanici 101 ve Kullanici 103 icin ortak arkadaslar: 102
Topluluklar:


Topluluk 1: 101 102 103
Toplam 1 topluluk bulundu.
En Etkili Kullanıcı:


Kullanici 101 -> 2 kisiye erisebiliyor.
En etkili kullanici: 101 (2 kisiye erisebiliyor)
Kullanım Notları
Maksimum kullanıcı sayısı: 100 (MAX_USERS)

Her kullanıcının maksimum arkadaş sayısı: 10 (MAX_FRIENDS)

Kullanıcı ID'leri 0'dan başlayarak numaralanır.

## Katkı Sağlama
Bu proje açık kaynaklıdır. Herhangi bir katkı yapmak isterseniz, pull request'lerinizi gönderebilirsiniz



