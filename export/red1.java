drive.trajectorySequenceBuilder(new Pose2d(-36, -66, Math.toRadians(90)))
	.splineTo(new Vector2d(-36, -36), Math.toRadians(90))
	.turn(Math.toRadians(90))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(180))
	.turn(Math.toRadians(-90))
	.splineTo(new Vector2d(-60, -24), Math.toRadians(90))
	.splineTo(new Vector2d(-48, -12), Math.toRadians(-0))
	.splineTo(new Vector2d(24, -12), Math.toRadians(-0))
	.splineTo(new Vector2d(36, -24), Math.toRadians(-90))
	.splineTo(new Vector2d(36, -36), Math.toRadians(-90))
	.turn(Math.toRadians(90))
	.splineTo(new Vector2d(48, -36), Math.toRadians(-0))
	.turn(Math.toRadians(-90))
	.splineTo(new Vector2d(48, -60), Math.toRadians(-90))
	.build();