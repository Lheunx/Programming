import hashlib


md5 = hashlib.md5()
#text = "dkdlvl1!" #패스워드 입력
#ipsol 접속

text = input()

hash = md5.update(text.encode('utf-8'))

pwd1 = md5.hexdigest()
pwd1 = pwd1[0:20]
print('path 1 : '+pwd1)

pwd2 = md5.hexdigest()
pwd2 = pwd2[12:]
print('path 2 : '+pwd2)

pwd = pwd1+pwd2

print('입력값 : '+text)
print('해쉬값 : '+pwd)


#function set_password($str)
#{
#    $pwd1 = substr(md5($str), 0, 20);
#    $pwd2 = substr(md5($str), -20);

#    return $pwd1 . $pwd2;
#}
