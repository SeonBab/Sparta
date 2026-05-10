# RPG_DesignPatterns

Microsoft Visual C++ (버전 2022 17.12.4)에서 구현 했습니다.  
ISO C++ 14 표준에서 구현 됐습니다.

`main.cpp`에는 프로그램의 실행 코드가 포함되어 있습니다.

## 플레이어 캐릭터(상태 패턴)

+ 상태 인터페이스: `PlayerState` 클래스

+ 구체적인 상태 구현: `NormalState`, `BerserkState` 클래스

+ 컨텍스트 클래스: `Player` 클래스

## 플레이어 캐릭터의 무기(전략 패턴)

+ 전략 인터페이스: `WeaponStrategy` 클래스

+ 구체적인 전략 구현: `Sword`, `Magic`, `Bow` 클래스

+ 해당 인터페이스를 포함하는 클래스: `Player` 클래스

## 전투 시나리오(템플릿 메서드 패턴)

+ 템플릿 메서드 인터페이스: `BattleScenario` 클래스

+ 구체적인 메서드 구현: `MobBattleScenario`, `BattleScenario` 클래스

## 아이템(빌더 패턴)

+ 빌더가 생성할 객체: `Item` 클래스

+ 빌더 인터페이스: `ItemBuilder` 클래스

+ 구체적인 빌더 구현: `PotionBuilder`, `WeaponBuilder` 클래스

+ 디렉터: `ItemDirector` 클래스