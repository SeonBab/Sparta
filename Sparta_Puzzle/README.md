# Sparta_Puzzle

스파르타 내일배움캠프에서 첫 C++ 언리얼 개인 과제입니다.

C++을 사용해 다양하게 움직이는 액터를 구현하는 과제입니다.

## 개발 환경

+ IDE: Visual Studio 2022
+ Unreal Engine: 5.5.1

## 빌드/실행 방법

`SpartaPuzzle.sln`를 실행시켜 사용하고 있는 IDE에서 빌드 > 솔루션 빌드를 합니다.  
혹은 `SpartaPuzzle.uproject`를 실행시킵니다.

## 의존 라이브러리/패키지

사용하고 있는 라이브러리 등 추가로 사용한 것은 없습니다.

## 프로젝트 개요

### 개발 기간

2025.01.23 ~ 2025.01.28

## 필수 과제

### **필수 과제 1번 - 서로 다른 Actor 클래스 2개 이상 구현**

- 각각 **StaticMeshComponent**를 가지며, 맵에 배치 가능한 형태여야 합니다.
- 두 클래스는 서로 **다른 동작 로직**을 수행해야 합니다.

### **필수 과제 2번 - Tick 함수 기반 동적 Transform 변경**

- **회전 기능**
    - `Tick(float DeltaTime)`에서 `AddActorLocalRotation()`(또는 유사 함수)을 사용해 **매 프레임 회전** 처리합니다.
- **이동 기능**
    - `Tick(float DeltaTime)`에서 위치를 변경해 **왕복 이동** (또는 원하는 이동)을 구현합니다.
    - `MoveSpeed`, `MaxRange`, `StartLocation` 등을 고려해 일정 범위를 벗어나면 이동 방향을 반전시키는 등의 자유로운 로직을 구성해봅니다.
- **프레임 독립성**
    - 이동/회전 시 반드시 `DeltaTime`을 활용하여, 하드웨어 성능에 따라 움직임이 달라지지 않도록 해야 합니다.

### **필수 과제 3번 - 리플렉션 적용**

- 주요 변수 (회전 속도, 이동 속도, 이동 범위 등)를 `UPROPERTY`로 선언, **에디터에서 조정 가능**하게 만들어야 합니다.
- 카테고리 (Category) 지정, `EditAnywhere` / `BlueprintReadWrite` 등 접근 지정자를 적절히 활용하여 **Details 패널**에서 편집 가능하게 만듭니다.
- 플레이 중에 Details 패널에서 값 변경 시, **즉시 반영**되는지 확인해 봅니다 (물론 이동 중이라면 Tick에서 계속 업데이트).

## 도전 과제

### **도전 과제 1번 - 시간 제한과 카운트다운 활용 (난이도 중상)**

- **타이머 활용**
    - `FTimerHandle`과 `GetWorld()->GetTimerManager().SetTimer(...)`를 사용해 N초 뒤 혹은 N초마다 특정 함수를 호출합니다.
    - 매 프레임 호출(`Tick`)이 아니라, 특정 **주기**로만 로직이 실행되므로 **퍼포먼스에도 이점**이 있습니다.
- **시간 제한이 적용된 로직 구현**
    - 예를 들어, 일정 시간 후 발판이 사라지거나, 일정 주기로 다른 메시/위치로 바뀌는 로직을 추가해봅니다. 여러분들의 창의력을 발휘해보세요.

### **도전 과제 2번 - 랜덤 퍼즐 생성 (난이도 상)**

- **동적 스폰**
    - 게임 시작 시 `SpawnActor`를 통해 **회전 발판/이동 플랫폼** 등을 **임의 좌표**에 여러 개 배치합니다. ([언리얼 공식 문서 참조](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/spawning-and-destroying-unreal-engine-actors))
    - 이를 통해 **로그라이크** 또는 **랜덤 스테이지**의 기초 개념을 체험해 볼 수 있습니다.
- **랜덤 속성 부여**
    - 회전/이동 속도, 이동 범위, 각도 등을 난수(`FMath::RandRange`)로 생성해 매번 다른 퍼즐 코스를 구성합니다.

## 프로젝트 구조

```
SpartaPuzzle
┃
┃
┣ Actor      // 디렉토리
┃ ┃
┃ ┣ SpawnActor.h      // 헤더
┃ ┣ SpawnActor.cpp    // 구현
┃ ┃
┃ ┣ BaseActor.h      // 헤더
┃ ┣ BaseActor.cpp    // 구현
┃ ┃
┃ ┣ MovingActor.h      // 헤더
┃ ┣ MovingActor.cpp    // 구현
┃ ┃
┃ ┣ RotatingActor.h      // 헤더
┃ ┣ RotatingActor.cpp    // 구현
┃ ┃
┃ ┣ HidingActor.h      // 헤더
┃ ┣ HidingActor.cpp    // 구현
┃ ┃
┃ ┣ FallingActor.h      // 헤더
┃ ┣ FallingActor.cpp    // 구현
┃
┃
┣ Player      // 디렉토리
┃ ┃
┃ ┣ PuzzleCharacter.h      // 헤더
┃ ┣ PuzzleCharacter.cpp    // 구현
┃ ┃
┃ ┣ PuzzlePlayerController.h      // 헤더
┃ ┣ PuzzlePlayerController.cpp    // 구현
```

## 클래스 다이어그램

![Image](https://github.com/user-attachments/assets/3d7c7b1b-b24b-4394-9a49-c10aa10b1bfc)

## 클래스 설명 및 핵심 로직

### SpawnActor

에디터의 프로퍼티로 `BaseActor`를 상속받은 클래스를 입력받아 게임 시작시 스폰시킵니다.

### BaseActor

모든 액터들이 필요한 스태틱 메시와 씬 컴포넌트를 가집니다.

### MovingActor

`BaseActor`를 상속받습니다.

매 틱마다 `DeltaTime`과 스피드 값을 기준으로 액터를 이동시킵니다.  
액터는 X, Y, Z 3방향으로 이동할 수 있도록 값을 `FVector`로 받았습니다.

기본적으로 게임 시작 시 랜덤으로 이동 스피드와, 최대 거리가 설정됩니다.

### RotatingActor

`BaseActor`를 상속받습니다.

매 틱마다 `DeltaTime`과 스피드 값을 기준으로 액터를 회전시킵니다.  
액터는 X, Y, Z 3방향으로 회전할 수 있도록 값을 `FRotator`로 받았습니다.

기본적으로 게임 시작 시 랜덤으로 회전 스피드가 설정됩니다.

### HidingActor

`BaseActor`를 상속받습니다.

타이머를 사용해서 `float`값을 받아 해당 값으로 메시가 렌더링 됐다 안됐다 하도록 구현했습니다.

### FallingActor

`BaseActor`를 상속받습니다.

타이머를 사용해서 `float`값을 받아 해당 값의 1/2 시간에 머리티얼이 변경되며, 해당 시간이 되면 피직스 시뮬레이션을 하며 액터가 추락합니다.

### 테스트 케이스

|테스트 제목|테스트 절차|케이스 분류|
|---|---|---|
|MovingActor 동작 체크|3개 축으로 이동이 잘 되는지, 1초마다 Speed만큼 이동하는지 확인|Normal|
|RotatingActor 동작 체크|3개 축으로 회전이 잘 되는지, 1초마다 Speed만큼 회전하는지 확인|Normal|
|HidingActor 동작 체크|특정 시간마다 렌더링 되고, 안되는지 확인|Normal|
|FallingActor 동작 체크|오버랩 후 특정 시간이 흐르며 머티리얼이 변경되고, 추락하는지 확인|Normal|
|FallingActor 오버랩 체크|오버랩이 여러번 된 경우 문제가 없는지 확인|Normal|

## 주의사항

현재 주의해야할 사항은 없는걸로 파악됩니다.
