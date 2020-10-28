def login(id):
    members = {'hhlim', 'huh604','dlagmdgus'}
    for member in members:
        if(member == id):
            print('로그인 성공')
            return
    print('로그인 실패')