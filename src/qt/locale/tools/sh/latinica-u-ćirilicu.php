<?php

// Od latinice do ćirilice
function latDoCir($rezultat)
{
 $tekst = $rezultat[1];
 $tekst = str_replace("A", "А", $tekst);
 $tekst = str_replace("a", "а", $tekst);
 $tekst = str_replace("B", "Б", $tekst);
 $tekst = str_replace("b", "б", $tekst);
 $tekst = str_replace("C", "Ц", $tekst);
 $tekst = str_replace("c", "ц", $tekst);
 $tekst = str_replace("Č", "Ч", $tekst);
 $tekst = str_replace("č", "ч", $tekst);
 $tekst = str_replace("Ć", "Ћ", $tekst);
 $tekst = str_replace("ć", "ћ", $tekst);

 // Dupla slova prije ostalih
 $tekst = str_replace("DŽ", "Џ", $tekst);  //DZ = DZ
 $tekst = str_replace("Dž", "Џ", $tekst);  //Dz = DZ
 $tekst = str_replace("dž", "џ", $tekst);  //dz = dz
 $tekst = str_replace("dŽ", "џ", $tekst);  //dZ = dz

 $tekst = str_replace("D", "Д", $tekst);
 $tekst = str_replace("d", "д", $tekst);
 $tekst = str_replace("Đ", "Ђ", $tekst);
 $tekst = str_replace("đ", "ђ", $tekst);
 $tekst = str_replace("E", "Е", $tekst);
 $tekst = str_replace("e", "е", $tekst);
 $tekst = str_replace("F", "Ф", $tekst);
 $tekst = str_replace("f", "ф", $tekst);
 $tekst = str_replace("G", "Г", $tekst);
 $tekst = str_replace("g", "г", $tekst);
 $tekst = str_replace("H", "Х", $tekst);
 $tekst = str_replace("h", "х", $tekst);
 $tekst = str_replace("I", "И", $tekst);
 $tekst = str_replace("i", "и", $tekst);

 // Slovo "J" poslije "Lj" i "Nj"

 $tekst = str_replace("K", "К", $tekst);
 $tekst = str_replace("k", "к", $tekst);

 // Dupla slova prije ostalih
 $tekst = str_replace("LJ", "Љ", $tekst);  //LJ = LJ
 $tekst = str_replace("Lj", "Љ", $tekst);  //Lj = LJ
 $tekst = str_replace("lj", "љ", $tekst);  //lj = lj
 $tekst = str_replace("lJ", "љ", $tekst);  //lJ = lj

 $tekst = str_replace("L", "Л", $tekst);
 $tekst = str_replace("l", "л", $tekst);
 $tekst = str_replace("M", "М", $tekst);
 $tekst = str_replace("m", "м", $tekst);

 // Dupla slova prije ostalih
 $tekst = str_replace("NJ", "Њ", $tekst);  //NJ = NJ
 $tekst = str_replace("Nj", "Њ", $tekst);  //Nj = NJ
 $tekst = str_replace("nj", "њ", $tekst);  //nj = nj
 $tekst = str_replace("nJ", "њ", $tekst);  //nJ = nj

 // Slovo "J"
 $tekst = str_replace("J", "Ј", $tekst);
 $tekst = str_replace("j", "ј", $tekst);

 $tekst = str_replace("N", "Н", $tekst);
 $tekst = str_replace("n", "н", $tekst);
 $tekst = str_replace("O", "О", $tekst);
 $tekst = str_replace("o", "о", $tekst);
 $tekst = str_replace("P", "П", $tekst);
 $tekst = str_replace("p", "п", $tekst);
 $tekst = str_replace("R", "Р", $tekst);
 $tekst = str_replace("r", "р", $tekst);
 $tekst = str_replace("S", "С", $tekst);
 $tekst = str_replace("s", "с", $tekst);
 $tekst = str_replace("Š", "Ш", $tekst);
 $tekst = str_replace("š", "ш", $tekst);
 $tekst = str_replace("T", "Т", $tekst);
 $tekst = str_replace("t", "т", $tekst);
 $tekst = str_replace("U", "У", $tekst);
 $tekst = str_replace("u", "у", $tekst);
 $tekst = str_replace("V", "В", $tekst);
 $tekst = str_replace("v", "в", $tekst);
 $tekst = str_replace("Z", "З", $tekst);
 $tekst = str_replace("z", "з", $tekst);
 $tekst = str_replace("Ž", "Ж", $tekst);
 $tekst = str_replace("ž", "ж", $tekst);

 $tekst = "<translation>" . $tekst . "</translation>";

 return $tekst;
}

$adresa1 = "bitcoin_sr-lat.ts";
$adresa2 = "bitcoin_sr.ts";
$datoteka = file_get_contents($adresa1);

$potraga = "/<translation>(.*?)<\/translation>/s";
$tekst = preg_replace_callback($potraga, "latDoCir", $datoteka);

// Izuzeci
$tekst = str_replace("&lt;бр/&gt;", "&lt;br/&gt;", $tekst);
$tekst = str_replace("&лт;б&гт;", "&lt;b&gt;", $tekst);
$tekst = str_replace("&лт;/б&гт;", "&lt;/b&gt;", $tekst);
$tekst = str_replace("&лт;", "&lt;", $tekst);
$tekst = str_replace("&гт;", "&gt;", $tekst);
$tekst = str_replace("&qуот;", "&quot;", $tekst);
$tekst = str_replace("&амп;", "&amp;", $tekst);
$tekst = str_replace("ДГ1KpSsSXd3uitgwHaA1i6T1Bj1hWEwAxB", "DG1KpSsSXd3uitgwHaA1i6T1Bj1hWEwAxB", $tekst);

// Izuzetak za "vdinar" malim slovima, ime programa
$tekst = str_replace("вдинар.цонф", "vdinar.conf", $tekst);
$tekst = str_replace("вдинар.пид", "vdinar.pid", $tekst);
$tekst = str_replace("вдинард", "vdinard", $tekst);
$tekst = str_replace("вдинаррпц", "vdinarrpc", $tekst);

$tekst = str_replace("<нумерусформ>", "<numerusform>", $tekst);
$tekst = str_replace("</нумерусформ>", "</numerusform>", $tekst);
$tekst = str_replace("wаллет.дат", "wallet.dat", $tekst);
$tekst = str_replace("ТЛСв1+ХИГХ:!ССЛв2:!аНУЛЛ:!еНУЛЛ:!АХ:!3ДЕС:@СТРЕНГТХ", "TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:@STRENGTH", $tekst);
$tekst = str_replace("хттпс://www.опенсоурце.орг/лиценсес/мит-лиценсе.пхп", "http://www.opensource.org/licenses/mit-license.php", $tekst);
$tekst = str_replace("хттпс://www.опенссл.орг", "http://www.openssl.org/", $tekst);
$tekst = str_replace("(Ериц Yоунг)", "(Eric Young)", $tekst);
$tekst = str_replace("(Тхомас Бернард)", "(Thomas Bernard)", $tekst);
$tekst = str_replace("еаy@црyптсофт.цом", "eay@cryptsoft.com", $tekst);
$tekst = str_replace("Битцоин", "Bitcoin", $tekst);
$tekst = str_replace("Литецоин", "Litecoin", $tekst);
$tekst = str_replace("-сервер", "-server", $tekst);
$tekst = str_replace("-проxy", "-proxy", $tekst);
$tekst = str_replace("-цоннецт", "-connect", $tekst);
$tekst = str_replace("рпцусер", "rpcuser", $tekst);
$tekst = str_replace("рпцпассwорд", "rpcpassword", $tekst);
$tekst = str_replace("%с", "%s", $tekst);
$tekst = str_replace("алертнотифy", "alertnotify", $tekst);
$tekst = str_replace("ецхо", "echo", $tekst);
$tekst = str_replace("маил -с", "mail -s", $tekst);
$tekst = str_replace("твоја@адреса.цом", "tvoja@adresa.com", $tekst);
$tekst = str_replace("-паyтxфее", "-paytxfee", $tekst);
$tekst = str_replace("-еxтерналип", "-externalip", $tekst);
$tekst = str_replace("-листен", "-listen", $tekst);
$tekst = str_replace("-тор", "-tor", $tekst);
$tekst = str_replace("-минрелаyтxфее", "-minrelaytxfee", $tekst);
$tekst = str_replace("-минтxфее", "-mintxfee", $tekst);
$tekst = str_replace("-дебуг", "-debug", $tekst);
$tekst = str_replace("-реиндеx", "-reindex", $tekst);
$tekst = str_replace("-тxиндеx", "-txindex", $tekst);
$tekst = str_replace("Цмд.еxе", "Cmd.exe", $tekst);
$tekst = str_replace("-аддноде", "-addnode", $tekst);
$tekst = str_replace("-сеедноде", "-seednode", $tekst);
$tekst = str_replace("-онлyнет", "-onlynet", $tekst);
$tekst = str_replace("%и", "%i", $tekst);
$tekst = str_replace("-соцкс", "-socks", $tekst);
$tekst = str_replace("&апос;", "&apos;", $tekst);
$tekst = str_replace("-бинд", "-bind", $tekst);
$tekst = str_replace("-еxтерналип", "-externalip", $tekst);
$tekst = str_replace("-паyтxфее", "-paytxfee", $tekst);
$tekst = str_replace("де_ДЕ", "de_DE", $tekst);

file_put_contents($adresa2, $tekst);

?>
