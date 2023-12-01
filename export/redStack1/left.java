drive.trajectorySequenceBuilder(new Pose2d(-36, -66, Math.toRadians(90)))
	.lineTo(new Vector2d(-54, -36))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(-0))
	.turn(Math.toRadians(180))
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineTo(new Vector2d(24, -60), Math.toRadians(-0))
	.splineTo(new Vector2d(48, -36), Math.toRadians(-0))
	.turn(Math.toRadians(-0))
	.splineTo(new Vector2d(24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(180))
	.turn(Math.toRadians(-0))
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineToConstantHeading(new Vector2d(24, -60), Math.toRadians(-0))
	.splineToConstantHeading(new Vector2d(48, -36), Math.toRadians(-0))
	.turn(Math.toRadians(-0))
	.splineTo(new Vector2d(24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(180))
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineToConstantHeading(new Vector2d(24, -60), Math.toRadians(-0))
	.splineToConstantHeading(new Vector2d(48, -36), Math.toRadians(-0))
	.turn(Math.toRadians(-0))
	.build();