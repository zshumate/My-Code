import sounds.APSoundClip;

class TestClip
{
	public static void main(String[]args)
	{
		APSoundClip clip = new APSoundClip("money.wav");
		clip.draw();
		clip.play();

		System.out.println("Length: " + clip.getLength());
		System.out.println("Sample at midpoint: " + clip.getSample(clip.getLength()/2));
	}
}
