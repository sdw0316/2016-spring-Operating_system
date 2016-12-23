1. myapp.c는 응용프로그램의 코드입니다. procfs에서  필요한 정보를 파싱해 출력해 줍니다.
2. init.txt, firefox.txt, myapp.txt, ramspeed.txt 는 application을 통해 나온 결과물을 txt파일로 뽑아낸 것입니다.
총 6개의 필드로 이루어 져있고 각각 PID, Name, VMSIZE, PMSIZE, SHARED, WSS을 나타냅니다. WSS필드의 값이 *이라는것은 working set size가 변화했음을 의미합니다.