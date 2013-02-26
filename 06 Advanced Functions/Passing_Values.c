int beep(int beeps)
{
	PlaySound(soundBeepBeep);
	return 0;
}

task main();
{
	StartTask (beep(10));
}
