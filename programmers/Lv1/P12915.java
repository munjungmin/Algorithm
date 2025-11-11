import java.util.*;

class Solution {

    public String[] solution(String[] strings, int n) {

        Arrays.sort(strings, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                if(s1.charAt(n) > s2.charAt(n)) return 1;
                else if(s1.charAt(n) == s2.charAt(n)) return s1.compareTo(s2);
                else return -1;
            }

        });

        return strings;
    }
}

//str.compareTo(str2)
// 음수: str이 사전순으로 str2보다 앞에 있음  this.charAt(k) - str2.charAt(k)


/**
Comparable<T> : 클래스의 기본 정렬 기준 compareTo(T o)
Comparator<T> : 커스텀 정렬 기준 compare(T o1, T o2)
*/


/*
익명 내부클래스: 이름없는 클래스 정의하면서 동시에 객체를 한번만 생성하는 문법

Comparator는 함수형 인터페이스이므로 람다식으로 더 간결하게 표현 가능

함수형 인터페이스 : 메서드가 하나만 있는 인터페이스
*/
