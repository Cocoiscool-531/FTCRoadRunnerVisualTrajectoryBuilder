drive.trajectorySequenceBuilder(new Pose2d(-36, -66, Math.toRadians(90)))
	.lineToLinearHeading(new Pose2d(-54, -36, Math.toRadians(-0)))
	.waitSeconds(0.5)
	.lineToConstantHeading(new Vector2d(-60, -36))
	.turn(Math.toRadians(180))
	.waitSeconds(0.5)
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineToConstantHeading(new Vector2d(12, -60), Math.toRadians(-0))
	.splineToConstantHeading(new Vector2d(48, -36), Math.toRadians(-0))
	.waitSeconds(0.5)
	.splineTo(new Vector2d(12, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(180))
	.waitSeconds(0.5)
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineToConstantHeading(new Vector2d(12, -60), Math.toRadians(-0))
	.splineToConstantHeading(new Vector2d(48, -36), Math.toRadians(-0))
	.waitSeconds(0.5)
	.splineTo(new Vector2d(12, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-24, -60), Math.toRadians(180))
	.splineTo(new Vector2d(-60, -36), Math.toRadians(180))
	.waitSeconds(0.5)
	.lineToConstantHeading(new Vector2d(-36, -54))
	.splineToConstantHeading(new Vector2d(12, -60), Math.toRadians(-0))
	.splineToConstantHeading(new Vector2d(48, -36), Math.toRadians(-0))
	.waitSeconds(0.5)
	.build();