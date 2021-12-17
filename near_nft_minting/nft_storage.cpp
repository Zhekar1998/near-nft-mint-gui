#include "nft_storage.h"
#include <curl/curl.h>
#include <QFile>
#include <QUrl>

NFT_Storage::NFT_Storage()
{

}

QString NFT_Storage::load_media(QString api, QString media)
{




   QString post = "curl -X POST --data-binary @"+media+" -H 'Authorization: Bearer "+ api + "' https://api.nft.storage/upload";
    QByteArray ba = post.toLocal8Bit();
      const char *c_str2 = ba.data();
    system(c_str2);
    CURL *curl;
    CURLcode res;
    char* temp = "https://api.nft.storage/upload";

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, temp);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
               fprintf(stderr, "curl_easy_perform() failed: %s\n",
                       curl_easy_strerror(res));

           /* always cleanup */
           curl_easy_cleanup(curl);
           QString str(curl_easy_strerror(res));

    }


}




