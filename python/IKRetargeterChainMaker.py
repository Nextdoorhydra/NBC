import unreal

def create_ik_chains():
    # 첨부해주신 이미지 구조를 그대로 반영한 체인 리스트
    chain_names = [
        "Neck", "Head", "Spine2", "Spine", "Hips",
        "LeftArm", "LeftHand", "LeftShoulder", "RightShoulder",
        "RightArm", "RightForeArm", "LeftForeArm", "RightHand",
        "LeftUpLeg", "LeftLeg", "LeftLegFoot", "LeftToeBase",
        "LeftToe_End", "RightToe_End", "RightToeBase",
        "RightLegFoot", "RightLeg", "RightUpLeg"
    ]

    # 콘텐츠 브라우저에서 현재 선택된 에셋 가져오기
    selected_assets = unreal.EditorUtilityLibrary.get_selected_assets()
    
    if not selected_assets:
        unreal.log_warning("먼저 콘텐츠 브라우저에서 IK Rig 에셋을 선택해주세요.")
        return

    for asset in selected_assets:
        # 선택된 에셋이 IK Rig인지 확인
        if isinstance(asset, unreal.IKRigDefinition):
            # 컨트롤러 가져오기 (UE 5.1 이상 지원)
            controller = unreal.IKRigController.get_controller(asset)
            
            for name in chain_names:
                # 체인 추가 (시작/종료 본은 매핑 보류를 위해 빈 문자열 처리)
                controller.add_retarget_chain(name, "", "")
            
            unreal.log(f"[{asset.get_name()}] 체인 일괄 생성 완료!")
        else:
            unreal.log_warning(f"[{asset.get_name()}] 은(는) IK Rig 에셋이 아닙니다.")

create_ik_chains()