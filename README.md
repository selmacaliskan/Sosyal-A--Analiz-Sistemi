# Sosyal-A-Analiz-Sistemi
İlişki ağacı oluşturarak (kullanıcılar için) Depth-first arama ile belirli mesafedeki arkadaşları bulur.Ortak arkadaş analizi Topluluk tespiti Etki alanı hesaplama (bir kullanıcının ağ üzerindeki etkisi)  yürütülür ayrıca krmızı-siyah ağaç veri yapısı kullanılarak, kullanıcıların kimlik bilgilerine göre dengeli bir arama yapısı oluşturulur.

# C Dilinde Sosyal Ağ Analizi

Bu depo, sosyal ağı modelleyen ve çeşitli sosyal ağ analiz tekniklerini uygulayan grafik ve ağaç veri yapıları kullanan bir C programını içerir.

## İçindekiler
- [Genel Bakış](#genel-bakış)
- [Özellikler](#özellikler)
- [Dizin Yapısı](#dizin-yapısı)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Teknik Detaylar](#teknik-detaylar)
- [Katkıda Bulunma](#katkıda-bulunma)
- [Lisans](#lisans)

## Genel Bakış

Bu program, kullanıcıları ve aralarındaki ilişkileri modelleyerek bir sosyal ağı simüle eder. Kullanıcılar arasındaki ilişkileri verimli şekilde saklamak ve analiz etmek için hem grafik hem de ağaç tabanlı veri yapıları uygular. Program, bir metin dosyasından veri okuyarak; belirli mesafedeki arkadaşları bulma, ortak arkadaşları tespit etme, toplulukları belirleme ve etkili kullanıcıları bulma gibi analizler gerçekleştirir.

## Özellikler

- **Kullanıcı Yönetimi**: Kullanıcı ekleme ve arkadaşlık ilişkileri kurma.  
- **Derinlik Öncelikli Arama (DFS)**: Belirli bir kullanıcıdan belirli mesafedeki arkadaşları bulma.  
- **Ortak Arkadaş Analizi**: İki kullanıcı arasındaki ortak arkadaşları belirleme. 
- **Topluluk Tespiti**: Ağ içindeki bağlantılı kullanıcı gruplarını tanımlama.  
- **Etkileşim Hesaplama**: Ulaşılan kullanıcı sayısına göre en etkili kullanıcıyı belirleme.  
- **Kırmızı-Siyah Ağaç (Red-Black Tree)**: Kullanıcı aramalarında verimli sorgulama için dengeli ağaç yapısı. 

## Dizin Yapısı

Kullanıcı Yönetimi: Kullanıcı ekleme ve arkadaşlık ilişkileri kurma.

Derinlik Öncelikli Arama (DFS): Belirli bir kullanıcıdan belirli mesafedeki arkadaşları bulma.

Ortak Arkadaş Analizi: İki kullanıcı arasındaki ortak arkadaşları belirleme.

Topluluk Tespiti: Ağ içindeki bağlantılı kullanıcı gruplarını tanımlama.

Etkileşim Hesaplama: Ulaşılan kullanıcı sayısına göre en etkili kullanıcıyı belirleme.

Kırmızı-Siyah Ağaç (Red-Black Tree): Kullanıcı aramalarında verimli sorgulama için dengeli ağaç yapısı.

Dizin Yapısı

css

Kopyala

Düzenle

.
├── README.md


├── src/

│   ├── social_network.c

│   ├── user.h

│   ├── rb_tree.h

│   ├── dfs.h

│   └── analysis.h

├── data/

│   └── veriseti.txt

├── Makefile

└── docs
/
    ├── technical_documentation.
    └── sample_output.md
Kurulum
Gereksinimler
GCC Derleyicisi

GNU Make (isteğe bağlı)

Derleme
GCC kullanarak:

bash
Kopyala
Düzenle
gcc -o social_network src/social_network.c -std=c99 -Wall
Make kullanarak:

bash
Kopyala
Düzenle
make
Kullanım
Aşağıdaki formatta veriseti.txt adlı bir veri dosyası oluşturun:

css
Kopyala
Düzenle
USER [id]
FRIEND [id1] [id2]
Açıklamalar:

USER [id]: Belirtilen ID’ye sahip yeni bir kullanıcı ekler.

FRIEND [id1] [id2]: İki kullanıcı arasında arkadaşlık ilişkisi kurar.

Derlenmiş programı çalıştırın:

bash
Kopyala
Düzenle
./social_network
Program aşağıdaki çıktıları üretir:

Kullanıcılar ve onların arkadaş listeleri.

Belirli mesafedeki arkadaşlar

İki kullanıcı arasındaki ortak arkadaşlar.

Ağdaki topluluklar

Kırmızı-siyah ağaçta kullanıcı arama sonucu.

Ağdaki en etkili kullanıcı

Teknik Detaylar
Veri Yapıları
Kullanıcı Yapısı
c
Kopyala
Düzenle
typedef struct User {
    int user_id;
    int friends[MAX_FRIENDS];
    int friend_count;
} User;
Kırmızı-Siyah Ağaç Düğümü
c
Kopyala
Düzenle
typedef struct RBNode {
    int user_id;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;
Temel Algoritmalar
Derinlik Öncelikli Arama (DFS): Sosyal grafiği dolaşmak için kullanılır.

Kırmızı-Siyah Ağaç İşlemleri: Dengeli arama işlemleri için.

Topluluk Tespiti: Bağlantılı bileşen analizi kullanılarak yapılır.

Etkileşim Hesaplama: Grafik dolaşımı ile erişim ölçülür.

Katkıda Bulunma
Katkılar memnuniyetle karşılanır! Lütfen Pull Request göndererek katkıda bulunun.

Lisans
Bu proje MIT Lisansı ile lisanslanmıştır – detaylar için LICENSE dosyasına bakınız.

İstersen bu içeriği Markdown dosyası olarak da dışa aktarabilirim. Yardımcı olmamı ister misin?






 MIT Lisansı ile lisanslanmıştır – detaylar için LICENSE dosyasına bakınız.
