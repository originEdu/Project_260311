#pragma once

//주머니 초기화
int* CreatePocket(int Size);

//두 주머니 동기화
void SynchronizingPocket(int* BasePocket, int* TargetPocket, int Size);

//주머니 셔플
void Shuffle(int* Pocket, int Size);

//공 뽑기
void PullOut(int* ShuffledPocket, int Number);