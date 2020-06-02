// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmBsnVlanXlatePortGroupIdVer12 implements OFOxmBsnVlanXlatePortGroupId {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnVlanXlatePortGroupIdVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 8;

        private final static ClassId DEFAULT_VALUE = ClassId.NONE;

    // OF message fields
    private final ClassId value;
//
    // Immutable default instance
    final static OFOxmBsnVlanXlatePortGroupIdVer12 DEFAULT = new OFOxmBsnVlanXlatePortGroupIdVer12(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnVlanXlatePortGroupIdVer12(ClassId value) {
        if(value == null) {
            throw new NullPointerException("OFOxmBsnVlanXlatePortGroupIdVer12: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x32204L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    public OFOxm<ClassId> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_VLAN_XLATE_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmBsnVlanXlatePortGroupId.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnVlanXlatePortGroupId.Builder {
        final OFOxmBsnVlanXlatePortGroupIdVer12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private ClassId value;

        BuilderWithParent(OFOxmBsnVlanXlatePortGroupIdVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x32204L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnVlanXlatePortGroupId.Builder setValue(ClassId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ClassId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_VLAN_XLATE_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmBsnVlanXlatePortGroupId build() {
                ClassId value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnVlanXlatePortGroupIdVer12(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnVlanXlatePortGroupId.Builder {
        // OF message fields
        private boolean valueSet;
        private ClassId value;

    @Override
    public long getTypeLen() {
        return 0x32204L;
    }

    @Override
    public ClassId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnVlanXlatePortGroupId.Builder setValue(ClassId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ClassId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public ClassId getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<ClassId> getMatchField() {
        return MatchField.BSN_VLAN_XLATE_PORT_GROUP_ID;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmBsnVlanXlatePortGroupId build() {
            ClassId value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnVlanXlatePortGroupIdVer12(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnVlanXlatePortGroupId> {
        @Override
        public OFOxmBsnVlanXlatePortGroupId readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x32204L
            int typeLen = bb.readInt();
            if(typeLen != 0x32204)
                throw new OFParseError("Wrong typeLen: Expected=0x32204L(0x32204L), got="+typeLen);
            ClassId value = ClassId.read4Bytes(bb);

            OFOxmBsnVlanXlatePortGroupIdVer12 oxmBsnVlanXlatePortGroupIdVer12 = new OFOxmBsnVlanXlatePortGroupIdVer12(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnVlanXlatePortGroupIdVer12);
            return oxmBsnVlanXlatePortGroupIdVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnVlanXlatePortGroupIdVer12Funnel FUNNEL = new OFOxmBsnVlanXlatePortGroupIdVer12Funnel();
    static class OFOxmBsnVlanXlatePortGroupIdVer12Funnel implements Funnel<OFOxmBsnVlanXlatePortGroupIdVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnVlanXlatePortGroupIdVer12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x32204L
            sink.putInt(0x32204);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnVlanXlatePortGroupIdVer12> {
        @Override
        public void write(ByteBuf bb, OFOxmBsnVlanXlatePortGroupIdVer12 message) {
            // fixed value property typeLen = 0x32204L
            bb.writeInt(0x32204);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnVlanXlatePortGroupIdVer12(");
        b.append("value=").append(value);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmBsnVlanXlatePortGroupIdVer12 other = (OFOxmBsnVlanXlatePortGroupIdVer12) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
